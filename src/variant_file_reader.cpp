#include "../include/variant_file_reader.h"

// helpers functions on strings
std::map<std::string, std::string> parse_key_values(
    std::string infostr, 
    const char sep
) {
    std::vector<std::string> split_infostr = split(infostr, sep);
    std::vector<std::string>::iterator itr;
    std::map<std::string, std::string> infomap;
    for(itr=split_infostr.begin();
        itr!=split_infostr.end();
        ++itr) {
        std::vector<std::string> s = split(*itr, '=');
        if (s.size() > 2) {
            std::cout << "Bad info " << *itr << std::endl;
            exit (EXIT_FAILURE);
        }
        if (s.size() == 1) {
           infomap[s[0]] = std::string ();
        } else {
           infomap[s[0]] = s[1];
        }
    }
    return infomap;
}

std::vector<std::string>& split(
    const std::string &s,
    const char sep,
    std::vector<std::string> &elems
) {
    std::stringstream ss(s);
    std::string aline;
    while (std::getline(ss, aline, sep)) {
        elems.push_back(aline);
    }
    return elems;
}

std::vector<std::string> split(
    const std::string &s,
    const char sep
) {
    std::vector<std::string> elems;
    split(s, sep, elems);
    return elems;
}

// VariantFileReader
VariantFileReader::VariantFileReader(std::string filepath){
    std::ifstream inFile(filepath);
    std::string aline;
    while (std::getline(inFile, aline)){
        //process aline
        if(aline.length() == 0) continue;
        char c1 = aline[0];
        if(aline[0] == '#') {
            if(aline[1] == '#') {
                std::vector<std::string> split_aline ;
                std::stringstream saline(aline.substr(2, std::string::npos));
                std::string key;
                std::getline(saline, key, '=');
                std::string value;
                std::getline(saline, value);
                //begin debug comment
                std::cout << "split meta-data line " << key << ",\t" <<  value << std::endl;
                //end debug comment
                if (metadata.count(key) == 0) {
                    metadata[key] = std::vector<std::string> ();
                }
                metadata[key].push_back(value);
            } else {
                header = aline.substr (1, std::string::npos);
            }
        } else {
            variants.push_back(aline);
        }
    }
}

// getters
std::string VariantFileReader::get_header() {
    return header;
}

std::string VariantFileReader::get_variant(int n){
    if (n > variants.size()) {
        return std::string ();
    }
    return variants[n];
}

std::vector<std::string> VariantFileReader::get_metainfo() {
    return metadata["INFO"];
}
// print info
void VariantFileReader::printMetadata(){
    std::map<std::string, std::vector<std::string> >::iterator mit;
    for (mit=metadata.begin(); mit!=metadata.end(); ++mit){
        std::cout << "for key " << mit->first << " in metadata " << std::endl;
        std::vector<std::string>::iterator vit;
        for (vit=mit->second.begin();
             vit!=mit->second.end();
             ++vit) {
            std::cout << ">>"  << *vit << std::endl;
        }
    }
}

void VariantFileReader::printVariants(){
    std::vector<std::string>::iterator vit;
    for (vit=variants.begin(); vit!=variants.end(); ++vit){
        std::cout << vit - variants.begin() << ":\t" 
                  << *vit << std::endl;
    }
}

void VariantFileReader::printHeader(){
    std::cout << header << std::endl;
}

