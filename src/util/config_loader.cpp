#include <iostream>
#include <sstream>
#include <algorithm>

#include "config_loader.hpp"

static std::string config_loader::del_spaces(std::string &str)
{
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

static bool config_loader::starts_with(std::string initial_str, std::string beginning_str)
{
    return !initial_str.compare(0, beginning_str.length(), beginning_str);
}

static std::map<std::string, std::string> config_loader::load_conf_params(){
    std::map<std::string, std::string> config_params;
    std::istringstream is_file(config_file_path);
    std::string line;

    while( std::getline(is_file, line) )
    {
        del_spaces(line);

        // skip comments
        if (starts_with(line, "#"))
            continue;

        std::istringstream is_line(line);
        std::string key;
        if( std::getline(is_line, key, '=') )
        {
            std::string value;
            if( std::getline(is_line, value) )
                config_params.insert(key, value);
        }
    }

}