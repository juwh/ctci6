#ifndef BTREEPRINTER_H_
#define BTREEPRINTER_H_

#include <cmath>
#include <iostream>
#include <vector>

template<typename T>
T* ptr(T& obj) { return &obj; }

template<typename T>
T* ptr(T* obj) { return obj; }

namespace ctcilib {
    template <typename T>
    class TreeNode;

    class BTreePrinter {
        private:
            template <typename T> 
            static void print_node_internal(const std::vector<const TreeNode<T>*> &nodes, size_t level, size_t max_level) {
                if (nodes.empty() || BTreePrinter::is_all_elements_null(nodes)) {
                    return;
                }
                size_t floor {max_level - level};
                size_t edge_lines = std::pow(2, (std::max(floor - 1, (size_t)0)));
                size_t first_spaces = std::pow(2, (floor)) - 1;
                size_t between_spaces = std::pow(2, (floor + 1)) - 1;

                BTreePrinter::print_whitespaces(first_spaces);

                std::vector<const TreeNode<T>*> new_nodes;
                for (auto node : nodes) {
                    if (node) {
                        std::cout << node->data_;
                        new_nodes.push_back(node->left_);
                        new_nodes.push_back(node->right_);
                    } else {
                        new_nodes.push_back(nullptr);
                        new_nodes.push_back(nullptr);
                        std::cout << " ";
                    }
                    BTreePrinter::print_whitespaces(between_spaces);
                }
                std::cout << std::endl;

                for (int i = 1; i <= (int)edge_lines; i++) {
                    for (int j = 0; j < (int)nodes.size(); j++) {
                        BTreePrinter::print_whitespaces(first_spaces - i);
                        if (!nodes.at(j)) {
                            BTreePrinter::print_whitespaces(edge_lines + edge_lines + i + 1);
                            continue;
                        }
                        if (nodes.at(j)->left_) {
                            std::cout << "/";
                        } else {
                            BTreePrinter::print_whitespaces(1);
                        }
                        BTreePrinter::print_whitespaces(i + i - 1);

                        if (nodes.at(j)->right_) {
                            std::cout << "\\";
                        } else {
                            BTreePrinter::print_whitespaces(1);
                        }
                        BTreePrinter::print_whitespaces(edge_lines + edge_lines - i);
                    }
                    std::cout << std::endl;
                }
                print_node_internal(new_nodes, level + 1, max_level);
            }
                        
            static void print_whitespaces(size_t count) {
                for (size_t i = 0; i < count; i++) {
                    std::cout << " ";
                }
            }

            template <typename T>
            static size_t max_level(const TreeNode<T>* node) {
                if (node == nullptr) {
                    return 0;
                }
                return std::max(max_level(node->left_), max_level(node->right_)) + 1;
            }

            template <typename T>
            static bool is_all_elements_null(std::vector<T> list) {
                for (T object : list) {
                    if (ptr(object)) {
                        return false;
                    }
                }
                return true;
            }
            
        public:
            template <typename T> 
            static void print_node(const TreeNode<T>* root) {
                size_t max = BTreePrinter::max_level(root);
                BTreePrinter::print_node_internal(std::vector<const TreeNode<T>*>{root}, 1, max);
            }
    };
}

#endif // BTREEPRINTER_H_