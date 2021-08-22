#include "Node.h"

Node::Node() : Node("", 0) {}

Node::Node(std::string vertex, size_t order) : vertex_{vertex}, state_{State::kUnvisited}, adjacent_count_{0}, order_{order} {}

void Node::add_adjacent(Node* x) {
    if (x->order_ != order_) {
        adjacent_.insert({x->order_, x});
        ++adjacent_count_;
    }
}

std::string Node::get_vertex() const {
    return vertex_;
}

void Node::remove_adjacent(size_t order) {
    if (adjacent_.count(order)) {
        adjacent_.extract(order);
        --adjacent_count_;
    }
}

State Node::get_state() const {
    return state_;
}

void Node::set_state(State state) {
    state_ = state;
}

size_t Node::get_order() const {
    return order_;
}

std::vector<size_t> Node::adjacent_orders() {
    std::vector<size_t> v;
    for (auto p : adjacent_) {
        v.push_back(p.first);
    }
    return v;
}

std::string Node::to_string() const {
    std::string str{get_vertex()};
    for (auto p : adjacent_) {
        str += "->" + p.second->get_vertex();
    }
    return str;
}