#ifndef __LOAD_FILE_DATA_OPTS_HPP_INCLUDED__
#define __LOAD_FILE_DATA_OPTS_HPP_INCLUDED__

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>
#include "../api/graph_vertex.hpp"

namespace load_file_data_opts {

    std::string del_spaces(std::string &);

// load config file methods
    std::string get_conf_file();

    std::map<std::string, std::string> load_conf_params();

// load graph file methods
    template<typename vertex_data_type, typename edge_data_type>
    std::vector<graph_vertex<vertex_data_type, edge_data_type>> load_graph(std::string file_path, int nvertices) {
        std::ifstream graph_file(file_path.c_str());
        std::string line;
        std::vector<graph_vertex<vertex_data_type, edge_data_type>> graph;

        graph.reserve(nvertices);

        for (int i = 0; i < nvertices; ++i)
            graph.push_back(graph_vertex<vertex_data_type, edge_data_type>(i));


        if (!graph_file.good()) {
            std::cout << "Error in reading file: " << graph_file << std::endl;
            exit(EXIT_FAILURE);
        }

        while (std::getline(graph_file, line)) {
            // skip comments
            if (line[0] == '#') continue;

            //skip empty lines
            if (line.length() == 0) continue;

            std::istringstream is_line(line);
            std::string vertex1;
            if (std::getline(is_line, vertex1, '\t')) {
                std::string vertex2;

                //TODO: treat it as an error
                if (vertex1.length() == 0) continue;

                if (std::getline(is_line, vertex2)) {
                    //TODO: treat it as an error
                    if (vertex2.length() == 0) continue;

                    graph_edge<edge_data_type> in_edge(atoi(vertex1.c_str()));
                    //TODO: initialize the data
                    //TODO: check for bounds
                    graph[atoi(vertex2.c_str())].add_in_edge(in_edge);

                    graph_edge<edge_data_type> out_edge(atoi(vertex2.c_str()));
                    //TODO: initialize the data
                    //TODO: check for bounds
                    graph[atoi(vertex1.c_str())].add_out_edge(out_edge);
                }
            }
        }

        return graph;
    }
}
//TODO: print_graph

#endif