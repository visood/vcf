/*
 * test the file reader
 */

#include "../include/variant_file_reader.h"

int main(int argc, char** argv){
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
    std::cout << "----------------METADATA----------------" << std::endl;
    sampleReader.printMetadata();
    std::cout << "----------------VARIANTS----------------" << std::endl;
    sampleReader.printVariants();
    std::cout << "----------------HEADER----------------" << std::endl;
    sampleReader.printHeader();

    std::cout << "---- the first few variants ------" << std::endl;
    int i;
    for(i = 0; i < 10; i++) {
        std::cout << sampleReader.get_variant(i) << std::endl;
    }
    return 0;
}

