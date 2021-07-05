#ifndef TRIE_H_
#define TRIE_H_

#include "TrieNode.h"

#include <vector>

namespace ctcilib {
    /* Implements a trie. We store the input list of words in tries so
    * that we can efficiently find words with a given prefix. 
    */ 
    class Trie
    {
        // The root of this trie.
        private:
            TrieNode root;

        public:
            /* Takes a list of strings as an argument, and constructs a trie that stores these strings. */    
            Trie(std::vector<std::string> list);

            /* Checks whether this trie contains a string with the prefix passed
            * in as argument.
            */
            bool contains(std::string prefix, bool exact);
            
            bool contains(std::string prefix);
            
            TrieNode* get_root();
    };
}

#endif // TRIE_H_