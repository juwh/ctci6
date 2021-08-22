#include "Project.h"

Project::Project(std::string n) : name_{n}, state_{State::kBlank}, dependencies_{0} {}

std::string Project::get_name() const {
    return name_;
}
void Project::add_neighbor(std::shared_ptr<Project> node) {
    if (node) {
        if (!map_.count(node->get_name())) {
            children_.push_back(node);
            map_.insert({node->get_name(), node});
            node->increment_dependencies();
        }
    }
}

State Project::get_state() const {
    return state_;
}

void Project::set_state(State st) {
    state_ = st;
}

std::vector<std::shared_ptr<Project>> Project::get_children() {
    return children_;
}

void Project::increment_dependencies() {
    ++dependencies_;
}

void Project::decrement_dependencies() {
    --dependencies_;
}

int Project::get_number_dependencies() {
    return dependencies_;
}

void Project::set_number_dependencies(size_t d) {
    dependencies_ = d;
}

std::string Project::to_string() const {
    std::string str{get_name()};
    for (auto p : children_) {
        str += "->" + p->get_name();
    }
    return str;
}