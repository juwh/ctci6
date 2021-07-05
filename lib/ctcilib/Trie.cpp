#include "Trie.h"

using namespace ctcilib;

/* Takes a list of strings as an argument, and constructs a trie that stores these strings. */
Trie::Trie(std::vector<std::string> list) : root{} {
    for (std::string word : list) {
        root.add_word(word);
    }
}  

/* Checks whether this trie contains a string with the prefix passed
    * in as argument.
    */
bool Trie::contains(std::string prefix, bool exact) {
    TrieNode* last_node = &root;
    for (size_t i = 0; i < prefix.length(); i++) {
        last_node = last_node->get_child(prefix.at(i));
        if (last_node == nullptr) {
            return false;	 
        }
    }
    return !exact || last_node->terminates();
}

bool Trie::contains(std::string prefix) {
    return contains(prefix, false);
}

TrieNode* Trie::get_root() {
    return &root;
}