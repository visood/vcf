#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <map>

// functions on strings

std::vector<std::string>& split(
    const std::string &s,
    const char sep,
    std::vector<std::string> &elems
);

std::vector<std::string> split(
    const std::string &s,
    const char sep
); 

std::map<std::string, std::string> parse_key_values(
    std::string infostr,
    const char sep
);

class VariantFileReader{
    private:
        std::map<std::string, std::vector<std::string> > metadata;
        std::vector<std::string> variants;
        std::string header;
    
    public:
    // constructor
    VariantFileReader(std::string filepath);

    // getters 
    std::string get_header();
    std::string get_variant(int n);
    std::vector<std::string> get_metainfo();
    // print info
    void printMetadata();
    void printVariants();
    void printHeader();
};
