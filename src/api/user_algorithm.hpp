#ifndef __USER_ALGORITHM_HPP_INCLUDED__
#define __USER_ALGORITHM_HPP_INCLUDED__

#include <iostream>
#include <string>
#include "graph_vertex.hpp"

template <typename vertex_data_type, typename edge_data_type>
class user_algorithm {

public:
    virtual void update(std::vector<graph_vertex <vertex_data_type, edge_data_type>> &, int ) = 0;
};

#endif