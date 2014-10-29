#ifndef __GIRCALPH_ENGINE_HPP_INCLUDED__
#define __GIRCALPH_ENGINE_HPP_INCLUDED__


#include <iostream>
#include <string>

#include "../util/load_file_data_opts.hpp"
#include "../util/cmdopts.hpp"
#include "../api/graph_vertex.hpp"
#include "../api/user_algorithm.hpp"

template <typename vertex_data_type, typename edge_data_type>
class gircalph_engine{
private:
    std::vector<graph_vertex <vertex_data_type, edge_data_type>> graph;
public:
    gircalph_engine(){

        // get parameters from config or user input
        int nvertices = cmdopts::get_int_value_by_system_param("nvertices");
        std::string file_path = cmdopts::get_string_value_by_system_param("file");

        // load graph in memory
        graph = load_file_data_opts::load_graph<vertex_data_type, edge_data_type>(file_path, nvertices);

//        std::cout<<x[0].get_edges().size()<<std::endl;
//        std::cout<<x[1].get_out_edges().size()<<std::endl;

    }

    void run(user_algorithm <vertex_data_type, edge_data_type> &alg){

        int nsupersteps = cmdopts::get_int_value_by_system_param("nsupersteps");

        //vale pragma
        for (int superstep = 0; superstep < nsupersteps; superstep++)
            alg.update(graph, superstep);


    }

};

#endif