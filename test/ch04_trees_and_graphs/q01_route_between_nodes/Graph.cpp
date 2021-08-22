#include "Graph.h"

const size_t kMaxVertices = 6;

Graph::Graph() : count_{0} {}

bool Graph::add_node(std::string vertex) {
    if (count_ < kMaxVertices) {
        vertices_.push_back(Node(vertex, count_));
        ++count_;
        return true;
    } else {
        std::cout << "Graph full" << std::endl;
        return false;
    }
}

bool Graph::pop_node() {
    if (count_) {
        for (auto& n : vertices_) {
            n.remove_adjacent(count_);
        }
        vertices_.pop_back();
        --count_;
        return true;
    } else {
        std::cout << "Graph empty" << std::endl;
        return false;
    }
}

Graph::Graph(const Graph& g) {
    for (Node n : g.vertices_) {
        auto status{add_node(n.get_vertex())};
        if (status) {
            set_state(n.get_order(), n.get_state());
        }
    }
    for (Node& n : vertices_) {
        for (size_t order : n.adjacent_orders()) {
            add_adjacent(n.get_order(), order);
        }
    }
}

const Graph& Graph::operator= (const Graph& rhs) {
    if (this != &rhs) {
        Graph tmp(rhs);
        std::swap(this->vertices_, tmp.vertices_);
        this->count_ = tmp.count_;
    }
    return *this;
}

Node* Graph::get_node(size_t index) {
    return &vertices_.at(index);
}

void Graph::add_adjacent(size_t target, size_t index) {
    vertices_.at(target).add_adjacent(&vertices_.at(index));
}

void Graph::remove_adjacent(size_t target, size_t index) {
    vertices_.at(target).remove_adjacent(index);
}

void Graph::set_state(size_t index, State state) {
    vertices_.at(index).set_state(state);
}

void Graph::reset_states() {
    for (auto n : vertices_) {
        n.set_state(State::kUnvisited);
    }
}

std::string Graph::to_string() const {
    std::string str{};
    for (auto& n : vertices_) {
        str += n.to_string() + "\n";
    }
    return str;
}