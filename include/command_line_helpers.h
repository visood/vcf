#include <algorithm>
#include<string>
#include<vector>
#include <iostream>

std::string get_command_option(std::vector<std::string> line, std::string option) ;

bool command_exists(std::vector<std::string> line, std::string option) ;

void filter_help();

bool all_options_provided(std::vector<std::string>);
