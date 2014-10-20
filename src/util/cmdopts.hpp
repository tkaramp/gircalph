#ifndef __CMDOPTS_HPP_INCLUDED__
#define __CMDOPTS_HPP_INCLUDED__

#include <string>
#include <map>
#include "load_file_data_opts.hpp"


namespace cmdopts {
    static std::map<std::string, std::string> system_params = load_file_data_opts::load_conf_params();
    void show_executable_usage();
    void system_init(int , char const ** );
    void init_system_parameters(int , const char **);
    int get_int_value_by_system_param(const char *);
    std::string get_string_value_by_system_param(const char *);
}

#endif