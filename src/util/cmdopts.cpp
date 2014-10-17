#include <iostream>
#include <map>
#include "cmdopts.hpp"
#include "config_loader.hpp"

std::map<std::string, std::string> cmdopts::system_params;

/* Private functions */

// print system executable's usage
void cmdopts::show_executable_usage() {
    std::cout<<"Usage: ./<executable> <flag1> <parameter1> ... <flagn> <parametern>"<<std::endl<<std::endl;
    std::cout<<"PARAMETERS"<<std::endl<<"\tAll the following parameters are optional. If a parameter is not " //
            "provided the system will try to load it from the configuration file"<<std::endl<<std::endl;

    // all available parameters
    std::cout<<"\t-f, --file"<<std::endl<<"\t\tPath to the graph containing file"<<std::endl<<std::endl;
    std::cout<<"\t-h, --help"<<std::endl<<"\t\tShows usage and type of parameters"<<std::endl<<std::endl;

}

/* Public functions */
void cmdopts::system_init(int argc, char const ** argv) {
    cmdopts::init_system_parameters(argc, argv);

    std::map<std::string,std::string>::iterator it;
    for( it = system_params.begin(); it != system_params.end(); it++){
        std::cout << it->first << " => " << it->second << '\n';
    }
}

void cmdopts::init_system_parameters(int argc, char const ** argv) {
    system_params = config_loader::load_conf_params();

    for (int i = 1; i < argc; i=i+2) {
        std::string flag = argv[i];

        if( !flag.compare("--file") || !flag.compare("-f")){
            // check if there is no file parameter after the flag
            if(i+1 == argc){
                std::cout<<"No file parameter after flag: "<<flag<<std::endl;
                show_executable_usage();
                exit(EXIT_FAILURE);
            }

            system_params["file"] = argv[i+1];
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

}


