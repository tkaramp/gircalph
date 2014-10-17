#ifndef __VERTEX_HPP_INCLUDED__
#define __VERTEX_HPP_INCLUDED__

#include <iostream>
#include <string>
#include <vector>

#include "edge.hpp"
template <typename VertexDataType>
class vertex {
private:
    int id;
    VertexDataType data;
    std::vector<edge> in_edges;
    std::vector<edge> out_edges;
public:
    inline VertexDataType getData() const {
        return data;
    }

    inline void setData(VertexDataType data) {
        vertex::data = data;
    }

    inline std::vector<edge> const &getOut_edges() const {
        return out_edges;
    }

    inline void setOut_edges(std::vector<edge> const &out_edges) {
        vertex::out_edges = out_edges;
    }

    inline std::vector<edge> const &getIn_edges() const {
        return in_edges;
    }

    inline void setIn_edges(std::vector<edge> const &in_edges) {
        vertex::in_edges = in_edges;
    }

    inline int getId() const {
        return id;
    }

    inline void setId(int id) {
        vertex::id = id;
    }
};

#endif