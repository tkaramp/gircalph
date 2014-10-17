#ifndef __GRAPH_VERTEX_HPP_INCLUDED__
#define __GRAPH_VERTEX_HPP_INCLUDED__

#include <iostream>
#include <string>
#include <list>

#include "graph_edge.hpp"
template <typename T>
class graph_vertex {
private:
    int vertex_id;
    T vertex_data;
    std::list<graph_edge> in_edges;
    std::list<edge> out_edges;
public:

    vertex(int vertex_id) : vertex_id(vertex_id) {
    }

    inline int get_id() const {
        return vertex_id;
    }

    inline void set_id(int vertex_id) {
        vertex::vertex_id = vertex_id;
    }

    inline std::list<graph_edge> const &get_in_edges() const {
        return in_edges;
    }

    inline void set_in_edges(std::list<graph_edge> const &in_edges) {
        vertex::in_edges = in_edges;
    }

    inline void add_in_edge(graph_edge const in_edge) {
        vertex::in_edges.push_front(in_edge);
    }

    inline std::list<graph_edge> const &get_out_edges() const {
        return out_edges;
    }

    inline void set_out_edges(std::list<graph_edge> const &out_edge) {
        vertex::out_edges = out_edges;
    }

    inline void add_out_edge(graph_edge const out_edge) {
        vertex::out_edges.push_front(out_edge);
    }

    inline T get_vertex_data() const {
        return vertex_data;
    }

    inline void set_vertex_data(T vertex_data) {
        vertex::vertex_data = vertex_data;
    }


};

#endif