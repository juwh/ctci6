#ifndef PROJECT_H_
#define PROJECT_H_

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

enum class State {
    kComplete,
    kPartial,
    kBlank
};

class Project {
    private:
        std::vector<std::shared_ptr<Project>> children_;
        std::unordered_map<std::string, std::shared_ptr<Project>> map_;
        std::string name_;
        State state_;
        int dependencies_;
    public:
        Project(std::string n);
        std::string get_name() const;
        void add_neighbor(std::shared_ptr<Project> node);
        State get_state() const;
        void set_state(State st);
        std::vector<std::shared_ptr<Project>> get_children();
        void increment_dependencies();
        void decrement_dependencies();
        int get_number_dependencies();
        void set_number_dependencies(size_t d);
        std::string to_string() const;
};

#endif // PROJECT_H_