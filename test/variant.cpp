#include "../include/variant.h"

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "please provide a path to the file to read" 
                  << std::endl;
        exit (EXIT_FAILURE);
    }
    if (argc > 2) {
        std::cout << "too many arguments!" << std::endl;
        exit (EXIT_FAILURE);
    }
    std::cout << "file path provied: " << argv[1] << std::endl;
    std::string fileName (argv[1]);
    VariantFileReader sampleReader (fileName);
    
    Variant first (sampleReader.get_variant(1));
    std::cout << "obtained first variant" << std::endl;
    std::vector<std::string>::iterator vitr;
    std::map<std::string, std::string>::iterator mitr;
    std::map<std::string, std::string> first_info = first.get_info();
    std::cout << "info on the first variant" << std::endl;
    for(mitr=first_info.begin(); 
        mitr!=first_info.end();
        ++mitr) {
        std::cout << ":\t" << mitr->first << ": " 
                  << mitr->second <<  std::endl;
    }
    std::vector<std::string> first_filter = first.get_filter();
    std::cout << "filters on the first variant" << std::endl;
    for(vitr=first_filter.begin(); 
        vitr!=first_filter.end();
        ++vitr) {
        std::cout << vitr - first_filter.begin() 
                  << ":\t" << *vitr <<  std::endl;
    }
    return 0;
}

