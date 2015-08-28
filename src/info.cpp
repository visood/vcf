#include "../include/info.h"
#include <boost/algorithm/string.hpp>

MetaInfo::MetaInfo(std::string infostring){
    boost::trim_left_if(infostring, boost::is_any_of("<"));
    boost::trim_right_if(infostring, boost::is_any_of(">"));

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

//getters

std::string MetaInfo::get_id() {
    return id;
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


//filter
bool MetaInfo::can_be_filtered(){
    if ((number != "1") and ((type != "Integer") or (type != "Float"))){
        std::cout << "filtering for INFO " << id << " with Number = " << number << " not implemented" << std::endl;
        std::cout << "please use only INFO with Number = 1 and Type = Integer or Float" << std::endl;
        return false;
    }
    else return true;
}

bool MetaInfo::keep_variant(std::string value1,
    std::string opr,
    std::string value2) {
    bool result;
    if (type == "Integer"){
            int v1 = stoi(value1);
            int v2 = stoi(value2);
            if (opr == "smaller") {
               result = v1 < v2;
            } else if (opr == "equal") {
                result = v1 == v2;
            } else if (opr == "larger") {
                result = v1 > v2;
            } else {
                std::cout << "unknown operator " << opr << std::endl;
                result = true;
            }
        } else if (type == "Float") {
            double v1 = stof(value1);
            double v2 = stof(value2);
            if (opr == "smaller") {
                result = v1 < v2;
            } else if (opr == "equal") {
                result = v1 == v2;
            } else if (opr == "larger") {
                result = v1 > v2;
            } else {
                std::cout << "unknown operator " << opr << std::endl;
                result = true;
            }
        } else {
            std::cout << "unknown / unimplemented type of info " << std::endl;
            result = true;
        }
    return result;
}




