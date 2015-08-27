#include "../include/info.h"
#include <boost/algorithm/string.hpp>

MetaInfo::MetaInfo(std::string infostring){
    boost::trim_left_if(infostring, boost::is_any_of("<"));
    boost::trim_right_if(infostring, boost::is_any_of(">"));

    //start debug comment
    std::cout << "trimmed string " << infostring << std::endl;
    //end debug comment
    std::map<std::string, std::string> infomap = parse_key_values(infostring, ',');
    id = infomap["ID"];
    number = infomap["Number"];
    type = infomap["Type"];
    description = infomap["Description"];
    if (infomap.count("Source") > 0) {
        source = infomap["Source"];
    } else {
        source = std::string();
    }
    if (infomap.count("Version") > 0) {
        version = infomap["Version"];
    } else {
        version = std::string();
    }

}

//print
void MetaInfo::print(int ntab) {
    std::cout << "--------METAINFO OBJECT------------";
    std::string stab;
    int i = 0;
    for (i = 0; i < ntab; i++){
        stab += '\t';
    }
    stab += '\n';
    std::cout << stab << "id: " << id << std::endl;
    std::cout << stab << "number: " << number << std::endl;
    std::cout << stab << "type: " << type << std::endl;
    std::cout << stab << "description: " << description << std::endl;
    std::cout << stab << "source: " << source << std::endl;
    std::cout << stab << "version: " << version << std::endl;
}


