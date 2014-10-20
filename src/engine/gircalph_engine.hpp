#include <iostream>
#include <string>

#include "../util/load_file_data_opts.hpp"
#include "../util/cmdopts.hpp"
#include "../api/graph_vertex.hpp"

template <typename vertex_data_type, typename edge_data_type>
class gircalph_engine{
private:
public:
    gircalph_engine(){
        int nvertices = cmdopts::get_int_value_by_system_param("nvertices");
        std::string file_path = cmdopts::get_string_value_by_system_param("file");
        std::cout<<file_path<<std::endl;
        std::vector<graph_vertex <vertex_data_type, edge_data_type>> x = load_file_data_opts::load_graph<vertex_data_type, edge_data_type>(file_path, nvertices);

        std::cout<<x.size()<<std::endl;
        std::cout<<x[0].get_edges().size()<<std::endl;
        std::cout<<x[1].get_out_edges().size()<<std::endl;


    }
};