#ifndef __CMDOPTS_HPP_INCLUDED__
#define __CMDOPTS_HPP_INCLUDED__

#include <string>
#include <map>

class cmdopts {
private:
    static std::map<std::string, std::string> system_params;

    static void show_executable_usage();
public:
    static void system_init(int , const char **);
    static void init_system_parameters(int , const char **);
    static int get_int_value_by_system_param(const char *);
    static std::string get_string_value_by_system_param(const char *);

};

#endif