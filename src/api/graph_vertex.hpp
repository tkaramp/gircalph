#ifndef __GRAPH_VERTEX_HPP_INCLUDED__
#define __GRAPH_VERTEX_HPP_INCLUDED__

#include <iostream>
#include <string>
#include <list>

#include "graph_edge.hpp"

template <typename vertex_data_type, typename edge_data_type>
class graph_vertex {
private:
    int vertex_id;
    vertex_data_type vertex_data;
    std::list<graph_edge<edge_data_type>> in_edges;
    std::list<graph_edge<edge_data_type>> out_edges;
public:

    inline graph_vertex(int vertex_id) : vertex_id(vertex_id) {
    }

    inline int get_id() const {
        return vertex_id;
    }

    inline void set_id(int vertex_id) {
        graph_vertex::vertex_id = vertex_id;
    }

    inline std::list<graph_edge<edge_data_type>> const get_edges() const {
        std::list<graph_edge<edge_data_type>> edges = get_in_edges(), out_edges = get_out_edges();
        edges.splice(edges.end(), out_edges);
        return edges;
    }

    inline std::list<graph_edge<edge_data_type>> const &get_in_edges() const {
        return in_edges;
    }

    inline void set_in_edges(std::list<graph_edge<edge_data_type>> const &in_edges) {
        graph_vertex::in_edges = in_edges;
    }

    inline void add_in_edge(graph_edge<edge_data_type> const in_edge) {
        graph_vertex::in_edges.push_front(in_edge);
    }

    inline std::list<graph_edge<edge_data_type>> const &get_out_edges() const {
        return out_edges;
    }

    inline void set_out_edges(std::list<graph_edge<edge_data_type>> const &out_edge) {
        graph_vertex::out_edges = out_edges;
    }

    inline void add_out_edge(graph_edge<edge_data_type> const out_edge) {
        graph_vertex::out_edges.push_front(out_edge);
    }

    //TODO: what happens if we call it with no data
    inline vertex_data_type get_vertex_data() const {
        return vertex_data;
    }

    inline void set_vertex_data(vertex_data_type vertex_data) {
        graph_vertex::vertex_data = vertex_data;
    }


};

#endif