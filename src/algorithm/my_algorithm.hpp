#ifndef __MY_ALGORITHM_HPP_INCLUDED__
#define __MY_ALGORITHM_HPP_INCLUDED__



#include <vector>
#include "../api/user_algorithm.hpp"
#include "../api/graph_vertex.hpp"

typedef float vertex_data_type;
typedef float edge_data_type;


#define THRESHOLD 1e-1
#define RANDOMRESETPROB 0.15

class my_algorithm : public user_algorithm<vertex_data_type, edge_data_type> {

    void update(std::vector<graph_vertex <vertex_data_type, edge_data_type>> &, int );

};

#endif