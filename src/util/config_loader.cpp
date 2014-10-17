#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>

#include "config_loader.hpp"

std::string config_loader::del_spaces(std::string &str)
{
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

std::string config_loader::get_conf_file() {
    return "../conf/gircalph.cnf";
}

std::map<std::string, std::string> config_loader::load_conf_params(){
    std::map<std::string, std::string> config_params;
    std::ifstream config_file(get_conf_file().c_str());
    std::string line;

    if(!config_file.good()){
        std::cout<<"Error in reading config file: "<< get_conf_file()<<std::endl;
        exit(EXIT_FAILURE);
    }

    while( std::getline(config_file, line) )
    {
        del_spaces(line);
        // skip comments
        if (line[0] == '#') continue;

        //skip empty lines
        if (line.length() == 0) continue;

        std::istringstream is_line(line);
        std::string key;
        if( std::getline(is_line, key, '=') )
        {
            std::string value;

            //TODO: treat it as an error
            if (key.length() == 0) continue;

            if( std::getline(is_line, value) ) {
                //TODO: treat it as an error
                if (key.length() == 0) continue;

                config_params[key] = value;
            }
        }
    }

    return config_params;

}