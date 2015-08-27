#include "../include/variant.h"

Variant::Variant(std::string variant_string) {
    //begin debug comment
    std::cout << "construct a variant from string "
              << variant_string << std::endl;
    //end debug comment
    std::vector<std::string> split_variant_string = split(variant_string, '\t');
    //begin debug comment
    std::cout << " string split to " << std::endl;
    std::vector<std::string>::iterator vit;
    for (vit=split_variant_string.begin(); 
            vit!=split_variant_string.end(); ++vit) {
        std::cout << split_variant_string.begin() - vit 
                  << ":\t" <<  *vit << std::endl;
    }
    //end debug comment
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
std::map<std::string, std::string> Variant::get_info() {
    return info;
}

std::vector<std::string> Variant::get_filter() {
    return filter;
}
