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

    //getters
        std::string get_id();
    //print
    void print(int ntab);

    //filter
    bool keep_variant(std::string value1, std::string opr, std::string value2);
};
