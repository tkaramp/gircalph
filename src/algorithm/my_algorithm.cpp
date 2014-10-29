#include "my_algorithm.hpp"
#include <iostream>

void my_algorithm::update(std::vector<graph_vertex <vertex_data_type, edge_data_type>> & graph, int superstep) {

    #pragma omp parallel for
    for (int vertex_id = 0; vertex_id < graph.size(); vertex_id++) {

        if (superstep > 0) {
            float sum=0;

            std::list<graph_edge<edge_data_type>> const &in_edges = graph[vertex_id].get_in_edges();

            std::list<graph_edge<edge_data_type>>::const_iterator iterator;
            for (iterator = in_edges.begin(); iterator != in_edges.end(); ++iterator) {
                const graph_vertex<vertex_data_type, edge_data_type> &neighbour_vertex = graph[(*iterator).get_connected_vertex_id()];
                sum += neighbour_vertex.get_vertex_data(superstep - 1);
            }

            int out_edges_num = graph[vertex_id].num_out_edges();

            if (out_edges_num  > 0)
                graph[vertex_id].set_vertex_data((RANDOMRESETPROB + (1 - RANDOMRESETPROB) * sum) / out_edges_num, superstep);
            else
                graph[vertex_id].set_vertex_data((RANDOMRESETPROB + (1 - RANDOMRESETPROB) * sum), superstep);


        } else if (superstep == 0) {
            int out_edges_num = graph[vertex_id].num_out_edges();
            if (out_edges_num > 0)
                graph[vertex_id].set_vertex_data(1.0f / (float) out_edges_num, superstep);
            else
                graph[vertex_id].set_vertex_data(0, superstep);
        }
    }


    for (int vertex_id = 0; vertex_id < graph.size(); vertex_id++) {
        if (superstep > 0)
            std::cout<<graph[vertex_id].get_vertex_data(superstep-1)<<std::endl;
        std::cout<<graph[vertex_id].get_vertex_data(superstep)<<std::endl;
        std::cout<<std::endl;
    }
    std::cout<<std::endl;


}

