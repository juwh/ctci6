#pragma region Interview Question
/*
4.1 Route Between Nodes: Given a directed graph, design an algorithm to find out whether there is a
route between two nodes. 
*/
#pragma endregion
#pragma region Hints
/*
Hints:
#127. Two well-known algorithms can do this. What are the tradeoffs between them?
*/
#pragma endregion

#include "Graph.h"

#include <deque>
#include <iostream>
#include <vector>

Graph create_new_graph() {
    Graph g;
    g.add_node("a");
    g.add_node("b");
    g.add_node("c");
    g.add_node("d");
    g.add_node("e");
    g.add_node("f");

    g.add_adjacent(0, 1);
    g.add_adjacent(0, 2);
    g.add_adjacent(0, 3);
    g.add_adjacent(3, 4);
    g.add_adjacent(4, 5);
    return g;
}

bool search(Graph* g, Node* start, Node* end) {
    std::deque<Node*> q;
    g->reset_states();
    q.push_back(start);
    while (!q.empty()) {
        auto node{q.front()};
        q.pop_front();
        for (auto order : node->adjacent_orders()) {
            auto adjacent{g->get_node(order)};
            if (adjacent->get_state() == State::kUnvisited) {
                if (adjacent == end) {
                    return true;
                } else {
                    adjacent->set_state(State::kVisiting);
                    q.push_back(adjacent);
                }
            }
        }
        node->set_state(State::kVisited);
    }
    return false;
}

int main() {
    Graph g{create_new_graph()};
    Node* start{g.get_node(3)};
    Node* end{g.get_node(5)};
    std:: cout << search(&g, start, end) << std::endl;
    //std::cout << g.to_string();
}