#ifndef GRAPH_H_
#define GRAPH_H_

#include "Project.h"

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

class Graph {
    private:
        std::unordered_map<std::string, std::shared_ptr<Project>> map_;
    public:
        Graph();
        std::shared_ptr<Project> get_or_create_node(std::string name);
        void add_edge(std::string start_name, std::string end_name);
        std::vector<std::shared_ptr<Project>> get_nodes();
        Graph(const Graph& g);
        const Graph& operator= (const Graph& rhs);
        std::string to_string() const;
        void reset_states();
};

#endif // GRAPH_H_