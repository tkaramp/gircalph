#include <iostream>
#include <map>
#include "cmdopts.hpp"



// print system executable's usage
void cmdopts::show_executable_usage() {
    std::cout<<"Usage: ./<executable> <flag1> <parameter1> ... <flagn> <parametern>"<<std::endl<<std::endl;
    std::cout<<"PARAMETERS"<<std::endl<<"\tAll the following parameters are optional. If a parameter is not " //
            "provided the system will try to load it from the configuration file"<<std::endl<<std::endl;

    // all available parameters
    std::cout<<"\t-f, --file"<<std::endl<<"\t\tPath to the graph containing file"<<std::endl<<std::endl;
    std::cout<<"\t-h, --help"<<std::endl<<"\t\tShows usage and type of parameters"<<std::endl<<std::endl;

}

void cmdopts::system_init(int argc, char const ** argv) {
    init_system_parameters(argc, argv);
}

void cmdopts::init_system_parameters(int argc, char const ** argv) {

    for (int i = 1; i < argc; i=i+2) {
        std::string flag = argv[i];

        if( !flag.compare("--file") || !flag.compare("-f")){
            // check if there is no file parameter after the flag
            if(i+1 == argc){
                std::cout<<"No file parameter after flag: "<<flag<<std::endl;
                show_executable_usage();
                exit(EXIT_FAILURE);
            }

            cmdopts::system_params["file"] = argv[i+1];
        }
        else if ( !flag.compare("--help") || !flag.compare("-h")){
            show_executable_usage();
            exit(EXIT_SUCCESS);
        }
        else{
            std::cout<<"Unknown flag: "<<flag<<std::endl;
            show_executable_usage();
            exit(EXIT_FAILURE);
        }
    }

    //TODO: check if all vital parameters have been initialized

}

int cmdopts::get_int_value_by_system_param(const char * system_param){
    if (cmdopts::system_params.find(system_param) != cmdopts::system_params.end())
        return atoi(cmdopts::system_params[system_param].c_str());

    std::cout<<"Unknow parameter: "<<system_param<<"required"<<std::endl;
    exit(EXIT_FAILURE);
}

std::string cmdopts::get_string_value_by_system_param(const char * system_param){
    if (cmdopts::system_params.find(system_param) != cmdopts::system_params.end())
        return cmdopts::system_params[system_param].c_str();

    std::cout<<"Unknow parameter: "<<system_param<<"required"<<std::endl;
    exit(EXIT_FAILURE);
}



