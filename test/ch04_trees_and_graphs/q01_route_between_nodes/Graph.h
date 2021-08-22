#ifndef GRAPH_H_
#define GRAPH_H_

#include "Node.h"

#include <iostream>
#include <vector>

class Graph {
    private:
        std::vector<Node> vertices_;
    public:
        size_t count_;
        Graph();
        bool add_node(std::string vertex);
        bool pop_node();
        Graph(const Graph& g);
        const Graph& operator= (const Graph& rhs);
        Node* get_node(size_t index);
        void add_adjacent(size_t target, size_t order);
        void remove_adjacent(size_t target, size_t order);
        State get_state(size_t index);
        void set_state(size_t index, State state);
        void reset_states();
        std::string to_string() const;
};

#endif // GRAPH_H_