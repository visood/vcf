#include "../include/variant.h"

Variant::Variant(std::string variant_string) {
    /*begin debug comment
    std::cout << "construct a variant from string "
              << variant_string << std::endl;
    //end debug comment
    */
    std::vector<std::string> split_variant_string = split(variant_string, '\t');
    /*begin debug comment
    std::cout << " string split to " << std::endl;
    std::vector<std::string>::iterator vit;
    for (vit=split_variant_string.begin(); 
            vit!=split_variant_string.end(); ++vit) {
        std::cout << split_variant_string.begin() - vit 
                  << ":\t" <<  *vit << std::endl;
    }
    //end debug comment
    */
    rep_string = variant_string;
    chrom = split_variant_string[0];
    pos = std::stoi(split_variant_string[1]);
    id = split_variant_string[2];
    ref = split_variant_string[3];
    alt = split_variant_string[4];
    qual = std::stof(split_variant_string[5]);
    if (split_variant_string[6] != "PASS") {
        filter = split(split_variant_string[6], ';');
    } else {
        filter = std::vector<std::string>();
    }
    info = parse_key_values(split_variant_string[7], ';');
    format = split_variant_string[8];
}



//getters
std::string Variant::get_variant_string() {
    return rep_string;
}
std::map<std::string, std::string> Variant::get_info() {
    return info;
}

std::vector<std::string> Variant::get_filter() {
    return filter;
}

bool Variant::has_info_on(std::string infoID) {
    return info.count(infoID) > 0;
}
// printers
void Variant::printInfo() {
    std::cout << "info on the variant" << std::endl;
    std::map<std::string, std::string>::iterator mitr;
    for(mitr=info.begin(); 
        mitr!=info.end();
        ++mitr) {
        std::cout << ":\t" << mitr->first << ": " 
                  << mitr->second <<  std::endl;
    }
}

void Variant::print_string() {
    std::cout << rep_string << std::endl;
}

void Variant::printInfo(std::string ID) {
    if (info.count(ID) == 0) {
        std::cout << "no info with ID " << ID << std::endl;
        return;
    }
    std::cout << " info associated with ID " << ID 
              << ":\t" << info[ID] << std::endl;
}



