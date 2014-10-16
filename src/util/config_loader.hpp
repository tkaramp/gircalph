#ifndef __CONFIG_LOADER_HPP_INCLUDED__
#define __CONFIG_LOADER_HPP_INCLUDED__

#include <iostream>
#include <map>
#include <string>

class config_loader {
private:
    static std::string config_file_path = "../../conf/gircalph.cnf";

    static std::string del_spaces(std::string &);
    static bool starts_with(std::string initial_str, std::string beginning_str);
public:
    static std::map<std::string, std::string> load_conf_params();
};

#endif