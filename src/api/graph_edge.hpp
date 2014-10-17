#ifndef __GRAPH_EDGE_HPP_INCLUDED__
#define __GRAPH_EDGE_HPP_INCLUDED__

template <typename T>
class graph_edge {

private:
    T   edge_data;
    int connected_vertex_id;

public:
    int get_Connected_vertex_id() const {
        return connected_vertex_id;
    }

    void set_connected_vertex_id(int connected_vertex_id) {
        graph_edge::connected_vertex_id = connected_vertex_id;
    }

    T get_edge_data() const {
        return edge_data;
    }

    void set_edge_data(T edge_data) {
        graph_edge::edge_data = edge_data;
    }
};

#endif