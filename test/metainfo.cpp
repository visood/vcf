#include "../include/info.h"

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

    std::vector<std::string> metainfo = sampleReader.get_metainfo();

    std::vector<std::string>::iterator vit;
    /*
    std::cout << "-----------------the metadata on INFO-------------";
    for(vit=metainfo.begin();
        vit!=metainfo.end();
        ++vit) {
        std::cout << *vit << std::endl;
    }
    */

    std::vector<MetaInfo> metainfoes;
    for(vit=metainfo.begin();
        vit!=metainfo.end();
        ++vit) {
        metainfoes.push_back(MetaInfo(*vit));
    }
    std::cout << "---------------METAINFO OBJECTS------------";
    std::vector<MetaInfo>::iterator mit;
    for(mit=metainfoes.begin();
        mit!=metainfoes.end();
        ++mit) {
        std::cout << mit - metainfoes.begin() << std::endl;
        mit->print(2);
    }
    return 0;
}

    

