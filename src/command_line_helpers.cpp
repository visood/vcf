#include "../include/command_line_helpers.h"

std::string get_command_option(std::vector<std::string> line, std::string option) {

    std::vector<std::string>::iterator vitr = std::find(line.begin(), line.end(), option);
    bool r =  vitr  != line.end() and ++vitr != line.end();
    if(not r) {
        std::cout << "Option " << option << " does not exist " << std::endl;
        std::cout << "Use option " << "-h" << " for help" << std::endl;
        return 0;
    }
    return *vitr;
}

bool command_exists(std::vector<std::string> line, std::string option) {
    std::vector<std::string>::iterator vitr;
    /*
    std::cout << "----------------" << std::endl;
    std::cout << "does the command exist?" << std::endl;
    for(vitr=line.begin();
        vitr!=line.end();
        ++vitr) {
        std::cout << *vitr << std::endl;
    }
    */

    vitr = std::find(line.begin(), line.end(), option);
    bool r =  vitr  != line.end();
    //std::cout << "and booled " << r << std::endl;
    return r;
}

void filter_help() {
    std::cout << "USAGE" <<  std::endl;
    std::cout << "  filter -i xxx -c xxx -v xxx -f xxx" << std::endl;
    std::cout << "Filter the variants in a VCF file using following options in your command." << std::endl;
    std::cout << "  -i: the info ID to filter on. " << std::endl;
    std::cout << "  -o: {'smaller', 'equal', 'larger'}. " 
              << " Should the info ID's value be smaller than, equal to, or larger than provided value ?" << std::endl;
    std::cout << "  -v: the value of the filter. " << std::endl;
    std::cout << "  -f: the VCF file path." << std::endl;
    std::cout << "ONLY A COMMAND WITH ALL REQUIRED FIELDS WILL SUCCEED. " << std::endl; 
}

bool all_options_provided(std::vector<std::string> arg_strings){
    if(arg_strings.size() < 9){
        return false;
    }
    if( command_exists(arg_strings, "-i") and
        command_exists(arg_strings, "-o") and
        command_exists(arg_strings, "-v") and
        command_exists(arg_strings, "-f")
    ) {
        return true;
    } else return false;
}


