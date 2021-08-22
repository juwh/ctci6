#pragma region Interview Question
/*
4.11 Random Node: You are implementing a binary tree class from scratch which, in addition to
insert, find, and delete, has a method getRandomNode() which returns a random node
from the tree. All nodes should be equally likely to be chosen. Design and implement an algorithm
for getRandomNode, and explain how you would implement the rest of the methods. 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#42. Be very careful in this problem to ensure that each node is equally likely and that
your solution doesn't slow down the speed of standard binary search tree algorithms
(l ike insert, find, and delete). Also, remember that even if you assume that it's a
balanced binary search tree, this doesn't mean that the tree is full/complete/perfect. 

#54. This is your own binary search tree class, so you can maintain any information about the
tree structure or nodes that you'd like (provided it doesn't have other negative implica-
tions, like making insert much slower). In fact, there's probably a reason the interview
question specified that it was your own class. You probably need to store some addi-
tional information in order to implement this efficiently. 

#62. As a naive "brute force" algorithm, can you use a tree traversal algorithm to implement
this algorithm? What is the runtime of this? 

#75. Alternatively, you could pick a random depth to traverse to and then randomly traverse,
stopping when you get to that depth. Think this through, though. Does this work? 

#89. Picking a random depth won't help us much. First, there's more nodes at lower depths
than higher depths. Second, even if we re-balanced these probabilities, we could
hit a "dead end" where we meant to pick a node at depth 5 but hit a leaf at depth 3.
Re-balancing the probabilities is an interesting, though. 

#99. A naive approach that many people come up with is to pick a random number between
1 and 3. If it's 1, return the current node. If it's 2, branch left. If it's 3, branch right. This
solution doesn't work. Why not? Is there a way you can adjust it to make it work? 

#112. The reason that the earlier solution (picking a random number between 1 and 3) doesn't
work is that the probabilities for the nodes won't be equal. For example, the root will be
returned with probability 1/3, even if there are 50+ nodes in the tree. Clearly, not all the
nodes have probability 1/3, so these nodes won't have equal probability. We can resolve
this one issue by picking a random number between 1 and size_of_tree instead.
This only resolves the issue for the root, though. What about the rest of the nodes? 

#119. The issue with the earlier solution is that there could be more nodes on one side of a
node than the other. So, we need to weight the probability of going left and right based
on the number of nodes on each side. How does this work, exactly? How can we know
the number of nodes?  
*/
#pragma endregion

#include "Tree.h"

#include <iostream>
#include <vector>

int main() {
    std::vector<int> array{{1, 0, 6, 2, 3, 9, 4, 5, 8, 7}};
    std::vector<int> counts(array.size());
    Tree tree;
    for (int x : array) {
        tree.insert_in_order(x);
    }
    for (int i = 0; i < 1000000; i++) {
        int d = tree.get_random_node()->data_;
        counts[d]++;
    }
    
    for (size_t i = 0; i < counts.size(); i++) {
        std::cout << std::to_string(i) + ": " + std::to_string(counts[i]) << std::endl;
    }

   /*
    Tree tree;
    std::vector<int> array{{1, 0, 6, 2, 3, 9, 4, 5, 8, 7}};
    for (int x : array) {
        tree.insert_in_order(x);
    }
    tree.print();
    */
}