#ifndef NODE_H_
#define NODE_H_

#include <string>
#include <unordered_map>
#include <vector>

enum class State {
    kUnvisited,
    kVisited,
    kVisiting
};

class Node {
    private:
        std::unordered_map<size_t, Node*> adjacent_;
        std::string vertex_;
        State state_;
        size_t adjacent_count_;
        size_t order_;
    public:
        Node();
        Node(std::string vertex, size_t order);
        void add_adjacent(Node* x);
        std::string get_vertex() const;
        void remove_adjacent(size_t order);
        State get_state() const;
        void set_state(State state);
        size_t get_order() const;
        std::vector<size_t> adjacent_orders();
        std::string to_string() const;
};

#endif // NODE_H_