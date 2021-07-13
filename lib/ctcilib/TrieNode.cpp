#include "TrieNode.h"

using namespace ctcilib;

TrieNode::TrieNode() {}

TrieNode::TrieNode(char character) : character_{character} {}

char TrieNode::get_char() {
    return character_;
}

void TrieNode::add_word(std::string word) {
    if (!word.empty()) {
        char first_char = word.at(0);

        TrieNode* child = get_child(first_char);
        if (!child) {
            child = new TrieNode(first_char);
            children_.insert({first_char, child});
        } 

        if (word.length() > 1) {
            child->add_word(word.substr(1));
        } else {
            child->set_terminates(true);
        };
    }
}

TrieNode* TrieNode::get_child(char c) {
    return children_.at(c);
}

bool TrieNode::terminates() {
    return terminates_;
}

void TrieNode::set_terminates(bool t) {
    terminates_ = t;
}