#include "variant_file_reader.h"

class MetaInfo {
    protected:
        std::string id;
        std::string number;
        std::string type; 
        std::string description;
        std::string source;
        std::string version;

    public:
    // constructors
        MetaInfo(std::string infostring);

    //print
    void print(int ntab);
};
