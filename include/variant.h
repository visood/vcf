#include "info.h"

/*
 * include the required fields in the Variant class.
 * there are details on each of the field in documentation,
 * and they can be more complex than reflected in code here.
 * i will focus on filter and info, implementing them according 
 * to the provided documentation at
 *  https://samtools.github.io/hts-specs/VCFv4.2.pdf
 */

class Variant {
    private:
        std::string rep_string;
        std::string chrom;
        int pos;
        std::string id;
        std::string ref;
        std::string alt;
        double qual;
        std::vector<std::string> filter;
        std::map<std::string, std::string> info;
        std::string format;


    public:
    // constructors
    Variant(std::string variant_string);

    //getters
    std::map<std::string, std::string> get_info();
    std::vector<std::string> get_filter();
    bool has_info_on(std::string);
    std::string get_variant_string();

    //print
    void printInfo();
    void printInfo(std::string);
    void print_string();
};
