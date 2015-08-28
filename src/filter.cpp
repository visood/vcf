#include "../include/command_line_helpers.h"
#include "../include/variant.h"

int main(int argc, char** argv) {
    std::vector<std::string> arg_strings;
    int i;
    for (i = 0; i < argc; i++){
        //std::cout << i << "\t" << std::string (argv[i]) << std::endl;
        arg_strings.push_back(std::string (argv[i]));
    }
    if( not all_options_provided(arg_strings) ){
        std::cout << "incomplete command" << std::endl;
        std::cout << "USAGE: " << std::endl;
        filter_help();
    }
    if (command_exists(arg_strings, "-h")){
        filter_help();
        return 0;
    }
    std::string infoID = get_command_option(arg_strings, "-i");
    //std::cout << "suggested info ID " << infoID << std::endl;
    std::string op = get_command_option(arg_strings, "-o");
    //std::cout << "suggested operator " << op << std::endl;
    std::string value  = get_command_option(arg_strings, "-v");
    //std::cout << "suggested value " << value << std::endl;
    std::string filename = get_command_option(arg_strings, "-f");
    //std::cout << "suggested filename " << filename << std::endl;
    
    VariantFileReader sampleFile = VariantFileReader(filename);




    //construct the metainfo
    std::vector<std::string> metainfo = sampleFile.get_metainfo();

    std::map<std::string, MetaInfo*> metainfoes {};
    std::vector<std::string>::iterator vit;
    for(vit=metainfo.begin();
        vit!=metainfo.end();
        ++vit) {
        MetaInfo* minfo = new MetaInfo(*vit);
        metainfoes[minfo->get_id()] = minfo;
    }
    std::map<std::string, MetaInfo*>::iterator mit;

    int number_variants = sampleFile.get_number_variants();
    if (not metainfoes.count(infoID)) {
        std::cout << "no metadata on  INFO with ID " << infoID << std::endl;
        exit(EXIT_FAILURE);
    }
    MetaInfo* reqdInfo = metainfoes[infoID];
    if(not reqdInfo->can_be_filtered()) {
        exit(EXIT_FAILURE);
    }
    // go through the variants, and filter them
    int num_variants_with_reqd_id = 0;
    std::vector<bool> filtered_variants;
    //out -- first we write back the meta info and the header
    std::vector<std::string> metadata_strings = sampleFile.get_metadata_strings();
    std::vector<std::string>::iterator msitr;
    for(msitr=metadata_strings.begin();
        msitr!=metadata_strings.end();
        ++msitr){
        std::cout << *msitr << std::endl;
    }

    //out -- then we create the new filter metadata, and push that out
    std::string newfilter;
    if (op == "equal") { 
        newfilter = "##FILTER=<ID=" + infoID +  "," +  
            "\"Description=" + infoID + " equal to " + value + "\">";
    } else if (op == "smaller") {
        newfilter = "##FILTER=<ID=" + infoID + "," +  
            "\"Description=" + infoID + " smaller than " + value + "\">";
    } else if (op == "larger"){
        newfilter = "##FILTER=<ID=" + infoID + "," +  
            "\"Description=" + infoID + " larger than  " + value + "\">";
    }

    if (newfilter.length() > 0) {
        std::cout << newfilter << std::endl;
    }

    //add the header
    std::cout << '#' + sampleFile.get_header() << std::endl;
    for (i = 0; i < number_variants; i++) {
        std::string variant_string = sampleFile.get_variant(i);
        Variant variant(variant_string);
        std::map<std::string, std::string> varinfo = variant.get_info();
        if (variant.has_info_on(infoID)) {
            num_variants_with_reqd_id += 1;
            bool kv = reqdInfo->keep_variant(varinfo[infoID], op, value);
            filtered_variants.push_back(kv);
            if (kv) {
                //variant.printInfo(reqdInfo->get_id());
                std::cout << variant.get_variant_string() << std::endl;
            }
        } else {
            filtered_variants.push_back(true);
        }
    }
    
    return 0;
}

