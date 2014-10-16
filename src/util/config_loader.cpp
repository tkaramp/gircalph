#include <iostream>
#include <sstream>
#include "config_loader.hpp"
#include <algorithm>
#include <locale>

// trim from start
static inline std::string &ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
static inline std::string &rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

// trim from both ends
static inline std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}


static std::map<std::string, std::string> config_loader::load_conf_params(){
    std::map<std::string, std::string> config_params;
    std::istringstream is_file(config_file_path);
    std::string line;

    while( std::getline(is_file, line) )
    {

        std::istringstream is_line(line);
        std::string key;
        if( std::getline(is_line, key, '=') )
        {
            std::string value;
            if( std::getline(is_line, value) )
                store_line(key, value);
        }
    }

}