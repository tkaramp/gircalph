#include <iostream>
#include <fstream>
#include <sstream>
#include "graph_loader.hpp"



/*std::map<std::string, std::string> graph_loader::load_graph(std::string file) {
    std::ifstream graph_file(file.c_str());
    std::string line;

    if(!graph_file.good()){
        std::cout<<"Error in reading file: "<< graph_file<<std::endl;
        exit(EXIT_FAILURE);
    }

    while( std::getline(graph_file, line) )
    {
        // skip comments
        if (line[0] == '#') continue;

        //skip empty lines
        if (line.length() == 0) continue;

        std::istringstream is_line(line);
        std::string vertex1;
        if( std::getline(is_line, vertex1, '\t') )
        {
            std::string vertex2;

            //TODO: treat it as an error
            if (key.length() == 0) continue;

            if( std::getline(is_line, value) ) {
                //TODO: treat it as an error
                if (key.length() == 0) continue;

                config_params[key] = value;
            }
        }
    }

}
*/