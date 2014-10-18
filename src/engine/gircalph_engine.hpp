#include <iostream>
#include <string>

#include "../util/graph_loader.hpp"
#include "../util/cmdopts.hpp"

template <typename vertex_data_type, typename edge_data_type>
class gircalph_engine{
private:
public:
    gircalph_engine(){
        int nvertices = cmdopts::get_int_value_by_system_param("nvertices");
        std::string file_path = cmdopts::get_string_value_by_system_param("file");
        std::vector<graph_vertex<vertex_data_type, edge_data_type>> x = graph_loader<vertex_data_type, edge_data_type>::load_graph(file_path, nvertices);

        std::cout<<x.size()<<std::endl;
    }
};