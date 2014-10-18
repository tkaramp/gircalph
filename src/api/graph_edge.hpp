#ifndef __GRAPH_EDGE_HPP_INCLUDED__
#define __GRAPH_EDGE_HPP_INCLUDED__

// T is edge_data_type
template <typename edge_data_type>
class graph_edge {

private:
    edge_data_type   edge_data;
    int connected_vertex_id;

public:

    inline graph_edge(int connected_vertex_id) : connected_vertex_id(connected_vertex_id) {
    }

    inline int get_connected_vertex_id() const {
        return connected_vertex_id;
    }

    inline void set_connected_vertex_id(int connected_vertex_id) {
        graph_edge::connected_vertex_id = connected_vertex_id;
    }

    inline edge_data_type get_edge_data() const {
        return edge_data;
    }

    inline void set_edge_data(edge_data_type edge_data) {
        graph_edge::edge_data = edge_data;
    }
};

#endif