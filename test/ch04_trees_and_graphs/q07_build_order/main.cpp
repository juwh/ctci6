#pragma region Interview Question
/*
4.7 Build Order: You are given a list of projects and a list of dependencies (which is a list of pairs of
projects, where the second project is dependent on the first project). All of a project's dependencies
must be built before the project is. Find a build order that will allow the projects to be built. If there
is no valid build order, return an error.

EXAMPLE
Input:
    projects: a, b, c, d, e, f
    dependencies: (a, d), (f, b), (b, d), (f, a), (d, c)
Output: f, e, a, b, d, c  
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#26. Build a directed graph representing the dependencies. Each node is a project and an
edge exists from A to B if B depends on A (A must be built before B). You can also build
it the other way if it's easier for you. 

#47. Look at this graph. Is there any node you can identify that will definitely be okay to build
first? 

#60. If you identify a node without any incoming edges, then it can definitely be built. Find
this node (there could be multiple) and add it to the build order. Then, what does this
mean for its outgoing edges? 

#85. Once you decide to build a node, its outgoing edge can be deleted. After you've done
this, can you find other nodes that are free and clear to build? 

#125. As a totally different approach: Consider doing a depth-first search starting from an arbi-
trary node. What is the relationship between this depth-first search and a valid build
order? 

#133. Pick an arbitrary node and do a depth-first search on it. Once we get to the end of a path,
we know that this node can be the last one built, since no nodes depend on it. What
does this mean about the nodes right before it?  
*/
#pragma endregion

#include "Graph.h"
#include "Project.h"

#include <deque>
#include <iostream>
#include <memory>
#include <deque>
#include <string>
#include <vector>

/* Build the graph, adding the edge (a, b) if b is dependent on a. 
 * Assumes a pair is listed in “build order” (which is the reverse 
 * of dependency order). The pair (a, b) in dependencies indicates
 * that b depends on a and a must be built before a. */
std::shared_ptr<Graph> build_graph(std::vector<std::string> projects, std::vector<std::vector<std::string>> dependencies) {
    auto graph{std::make_shared<Graph>()};
    for (std::string project : projects) {
        graph->get_or_create_node(project);
    }
    
    for (std::vector<std::string> dependency : dependencies) {
        graph->add_edge(dependency[0], dependency[1]);
    }
    return graph;
}

/* A helper function to insert projects with zero dependencies 
 * into the order array, starting at index offset. */
size_t add_non_dependent(std::vector<std::shared_ptr<Project>>& order, const std::vector<std::shared_ptr<Project>>& projects, size_t offset) {
    for (auto project : projects) {
        if (project->get_number_dependencies() == 0) {
            order.push_back(project);
            offset++;
        }
    }
    return offset;
}

std::deque<Project> order_projects(Graph* graph) {
    std::deque<Project> deque_order;
    std::vector<std::shared_ptr<Project>> order;
    
    /* Add “roots” to the build order first.*/
    auto projects{graph->get_nodes()};
    size_t end_of_list{add_non_dependent(order, projects, 0)};
    
    size_t to_be_processed{0};
    while (to_be_processed < order.size()) {
        auto current{order.at(to_be_processed)};
        
        /* Remove myself as a dependency. */
        auto children{current->get_children()};
        for (auto child : children) {
            child->decrement_dependencies();
        }
        
        /* Add children that have no one depending on them. */
        end_of_list = add_non_dependent(order, children, end_of_list);
        
        to_be_processed++;
    }
    /* We have a circular dependency since there are no remaining
     * projects with zero dependencies. */ 
    if (to_be_processed != projects.size()) {
        return deque_order;
    }
    for (auto project : order) {
        deque_order.push_back(Project(project->get_name()));
    }
    return deque_order;
}

bool dfs_visit(std::shared_ptr<Project> project, std::deque<Project>& deque_order) {
    if (project->get_state() == State::kPartial) {
        deque_order.clear();
        return false; // cycle
    }
    if (project->get_state() == State::kBlank) {
        project->set_state(State::kPartial);
        for (auto v : project->get_children()) {
            if (!dfs_visit(v, deque_order)) {
                deque_order.clear();
                return false;
            }
        }
        project->set_state(State::kComplete);
        deque_order.push_front(Project(project->get_name()));
    }
    return true;
}

std::deque<Project> order_projects_dfs(Graph* graph) {
    std::deque<Project> deque_order;
    for (auto project : graph->get_nodes()) {
        if (!dfs_visit(project, deque_order)) {
            return deque_order;
        };
    }
    return deque_order;
}

std::vector<std::string> convert_to_string_list(std::deque<Project> projects) {
    std::vector<std::string> build_order;
    auto deque_size{projects.size()};
    for (size_t i = 0; i < deque_size; i++) {
        build_order.push_back(projects.front().get_name());
        projects.pop_front();
    }
    return build_order;
}

std::deque<Project> find_build_order(std::vector<std::string> projects, std::vector<std::vector<std::string>> dependencies) {
    auto graph{build_graph(projects, dependencies)};
    graph->reset_states();
    //return order_projects(graph.get());
    return order_projects_dfs(graph.get());
}

std::vector<std::string> build_order_wrapper(std::vector<std::string> projects, std::vector<std::vector<std::string>> dependencies) {
    std::deque<Project> build_order = find_build_order(projects, dependencies);
    std::vector<std::string> build_order_string{convert_to_string_list(build_order)};
    return build_order_string;
}

int main() {
    std::vector<std::string> projects{{"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"}};
    std::vector<std::vector<std::string>> dependencies = {
        {"a", "b"},
        {"b", "c"},
        {"a", "c"},
        {"d", "e"},
        {"b", "d"},
        {"e", "f"},
        {"a", "f"},
        {"h", "i"},
        {"h", "j"},
        {"i", "j"},
        {"g", "j"}
    };
    //Graph graph{build_graph(projects, dependencies)};
    //std::cout << graph.to_string() << std::endl;
        
    std::vector<std::string> build_order{build_order_wrapper(projects, dependencies)};
    if (!build_order.size()) {
        std::cout << "Circular Dependency." << std::endl;
    } else {
        for (std::string s : build_order) {
            std::cout << s << std::endl;
        }
    }
}