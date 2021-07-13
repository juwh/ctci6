#ifndef TRIENODE_H_
#define TRIENODE_H_

#include <unordered_map>

namespace ctcilib {
    /* One node in the trie. Most of the logic of the trie is implemented
    * in this class.
    */
    class TrieNode {
        private:
            /* The children of this node in the trie.*/
            std::unordered_map<char, TrieNode*> children_;
            bool terminates_ {false};

            // The character stored in this node as data.
            char character_;	

        public:
            /* Constructs a trie node and stores this character as the node's value.
            * Initializes the list of child nodes of this node to an empty hash map. */
            TrieNode();

            /* Constructs a trie node and stores in the node the char passed in
            * as the argument. Initializes the list of child nodes of this
            * node to an empty hash map.
            */
            TrieNode(char character);

            /* Returns the character data stored in this node. */
            char get_char();

            /* Add this word to the trie, and recursively create the child
            * nodes. */

            void add_word(std::string word);
            /* Find a child node of this node that has the char argument as its
            * data. Return null if no such child node is present in the trie.
            */
            TrieNode* get_child(char c);

            /* Returns whether this node represents the end of a complete word. */
            bool terminates();
            
            /* Set whether this node is the end of a complete word.*/
            void set_terminates(bool t);
    };
}

#endif // TRIENODE_H_