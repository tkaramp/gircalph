#ifndef __CONFIG_LOADER_HPP_INCLUDED__
#define __CONFIG_LOADER_HPP_INCLUDED__

#include <iostream>
#include <string>
#include <map>

class config_loader {
private:
    static std::string del_spaces(std::string &);
    static bool starts_with(std::string initial_str, std::string beginning_str);
    static std::string get_conf_file();
public:

    static std::map<std::string, std::string> load_conf_params();
};

#endif