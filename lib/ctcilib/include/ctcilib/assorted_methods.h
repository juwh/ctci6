#ifndef ASSORTED_METHODS_H_
#define ASSORTED_METHODS_H_

#include "LinkedListNode.h"
#include "TreeNode.h"
#include "Trie.h"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <queue>
#include <random>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>

namespace ctcilib {
    int random_int(int n);
    int random_int_in_range(int min, int max);
    bool random_boolean();
    bool random_boolean(int percent_true);
    std::vector< std::vector<bool> > random_boolean_matrix(int m, int n, int percent_true);
    std::vector< std::vector<int> > random_matrix(int m, int n, int min, int max);
    std::vector<int> random_array(int n, int min, int max);
    LinkedListNode<int> random_linked_list(size_t n, int min, int max);
    LinkedListNode<int> linked_list_with_value(size_t n, int value);
    LinkedListNode<int> create_linked_list_from_array(std::vector<int> vals);
    std::string array_to_string(std::vector<int> array, size_t start, size_t end);
    std::string array_to_string(std::vector<int> array);
    std::string string_array_to_string(std::vector<std::string> array);
    std::string to_full_binary_string(int a);
    std::string to_base_n_string(int a, int base);
    void print_matrix(std::vector< std::vector<int> > matrix);
    void print_matrix(std::vector< std::vector<bool> > matrix);
    void print_int_array(std::vector<int> array);
    std::string char_array_to_string(char* array);
    std::string list_of_points_to_string(std::vector<std::tuple<int, int>> list);
    TreeNode<int> random_bst(size_t n, int min, int max);
    /* Creates tree by mapping the array left to right, top to bottom. */
    TreeNode<int> create_tree_from_array(std::vector<int> array);
    std::string get_long_text_blob();
    std::vector<std::string> get_long_text_blob_as_string_list();
    std::vector<std::string> get_list_of_words();
    Trie get_trie_dictionary();
    std::unordered_set<std::string> get_word_list_as_hash_set();
}

#endif // ASSORTED_METHODS_H_