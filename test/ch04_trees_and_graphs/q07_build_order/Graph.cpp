#include "Graph.h"

Graph::Graph() {}

std::shared_ptr<Project> Graph::get_or_create_node(std::string name) {
    if (!map_.count(name)) {
        map_.insert({name, std::make_shared<Project>(name)});
    }
    return map_.at(name);
}

void Graph::add_edge(std::string start_name, std::string end_name) {
    auto start{get_or_create_node(start_name)};
    auto end{get_or_create_node(end_name)};
    start->add_neighbor(end);
}

std::vector<std::shared_ptr<Project>> Graph::get_nodes() {
    std::vector<std::shared_ptr<Project>> v;
    for (auto p : map_) {
        v.push_back(p.second);
    }
    return v;
}

Graph::Graph(const Graph& g) {
    for (auto p : g.map_) {
        for (auto p_ptr : p.second->get_children()) {
            if (p_ptr) {
                add_edge(p.second->get_name(), p_ptr->get_name());
            }
        }
        if (map_.count(p.second->get_name())) {
            map_.at(p.second->get_name())->set_state(p.second->get_state());
        }
    }
}

const Graph& Graph::operator= (const Graph& rhs) {
    if (this != &rhs) {
        Graph tmp(rhs);
        std::swap(this->map_, tmp.map_);
    }
    return *this;
}

std::string Graph::to_string() const {
    std::string str{};
    for (auto& p : map_) {
        str += p.second->to_string() + "\n";
    }
    return str;
}

void Graph::reset_states() {
    for (auto p : map_) {
        p.second->set_state(State::kBlank);
        p.second->set_number_dependencies(0);
    }
    for (auto p : map_) {
        for (auto d : p.second->get_children()) {
            d->increment_dependencies();
        }
    }
}