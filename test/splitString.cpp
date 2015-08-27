/*
 * we need to split line strings
 * so test splitting
 */

#include "../include/variant_file_reader.h"

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "please provide a path to the file to read" << std::endl;
        exit (EXIT_FAILURE);
    }
    if (argc > 2) {
        std::cout << "too many arguments!" << std::endl;
        exit (EXIT_FAILURE);
    }
    std::cout << "file path provied: " << argv[1] << std::endl;
    std::string fileName (argv[1]);
    VariantFileReader sampleReader (fileName);

    std::vector<std::string> headerElems_space = split(sampleReader.get_header(), ' ');
    std::cout << "number of header elements, split by space: " 
              << headerElems_space.size() 
              << std::endl;
    std::vector<std::string>::iterator vit;
    for (vit=headerElems_space.begin(); vit!=headerElems_space.end(); ++vit) {
        std::cout << *vit << std::endl;
    }

    std::cout << "--------------------------------------------------" << std::endl;
    std::vector<std::string> headerElems_tab = split(sampleReader.get_header(), '\t');
    std::cout << "number of header elements, split by tab: " 
              << headerElems_tab.size() 
              << std::endl;
    for (vit=headerElems_tab.begin(); vit!=headerElems_tab.end(); ++vit) {
        std::cout << *vit << std::endl;
    }

    // next we split the first line from the variants

    std::cout << "---------------------------------------------------" << std::endl;
    std::vector<std::string> firstVariant = split(sampleReader.get_variant(1), '\t');
    std::cout << "number of elements in the first variant, split by tab:"
              << firstVariant.size()
              << std::endl;
    for (vit=firstVariant.begin(); vit!=firstVariant.end(); ++vit) {
        std::cout << *vit << std::endl;
    }

    return 0;
}

