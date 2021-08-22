#pragma region Interview Question
/*
4.8 First Common Ancestor: Design an algorithm and write code to find the first common ancestor
of two nodes in a binary tree. Avoid storing additional nodes in a data structure. NOTE: This is not
necessarily a binary search tree. 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#10. If each node has a link to its parent, we could leverage the approach from question 2.7
on page 95. However, our interviewer might not let us make this assumption. 

#16. The first common ancestor is the deepest node such that p and q are both descendants.
Think about how you might identify this node. 

#28. How would you figure out if p is a descendent of a node n? 

#36. Start with the root. Can you identify if root is the first common ancestor? If it is not, can
you identify which side of root the first common ancestor is on? 

#46. Try a recursive approach. Check if p and q are descendants of the left subtree and the
right subtree. If they are descendants of different subtrees, then the current node is the
first common ancestor. If they are descendants of the same subtree, then that subtree
holds the first common ancestor. Now, how do you implement this efficiently? 

#70. In the more naive algorithm, we had one method that indicated if x is a descendent
of n, and another method that would recurse to find the first common ancestor. This is
repeatedly searching the same elements in a subtree. We should merge this into one
firstCommonAncestor function. What return values would give us the information
we need? 

#80. The firstCommonAncestor function could return the first common ancestor (if p
and q are both contained in the tree), p if P is in the tree and not q, q if q is in the tree
and not p, and null otherwise. 

#96. Careful! Does your algorithm handle the case where only one node exists? What will
happen? You might need to tweak the return values a bit. 
*/
#pragma endregion

#include <ctcilib/TreeNode.h>

#include <iostream>
#include <memory>
#include <string>
#include <vector>

int depth(ctcilib::TreeNode<int>* n) {
    int count{};
    while (n) {
        n = n->parent_;
        ++count;
    }
    return count;
}

ctcilib::TreeNode<int>* go_up_by(ctcilib::TreeNode<int>* node, size_t delta) {
    for (size_t i = 0; node && i < abs(delta); i++) {
        node = node->parent_;
    }
    return node;
}

ctcilib::TreeNode<int>* common_ancestor_a(ctcilib::TreeNode<int>* p, ctcilib::TreeNode<int>* q) {
    int delta{depth(p) - depth(q)};
    auto shallower{delta > 0 ? q : p};
    auto deeper{delta > 0 ? p : q};
    deeper = go_up_by(deeper, delta);
    while (deeper && shallower && deeper != shallower) {
        shallower = shallower->parent_;
        deeper = deeper->parent_;
    }
    return !shallower || !deeper ? nullptr : shallower;
}

bool covers(ctcilib::TreeNode<int>* root, ctcilib::TreeNode<int>* p) {
    if (!root) {
        return false;
    }
    if (root == p) {
        return true;
    }
    return covers(root->left_, p) || covers(root->right_, p);

}

ctcilib::TreeNode<int>* get_sibling(ctcilib::TreeNode<int>* node) {
    if (!node || !node->parent_) {
        return nullptr;
    }
    auto parent{node->parent_};
    return parent->left_ == node ? parent->right_ : parent->left_;
}

ctcilib::TreeNode<int>* common_ancestor_b(ctcilib::TreeNode<int>* p, ctcilib::TreeNode<int>* q) {
    if (!p || !q) {
        return nullptr;
    }
    if (covers(p, q)) {
        return p;
    }
    if (covers(q, p)) {
        return q;
    }

    /* Traverse upwards until you find a node that covers q. */
    auto sibling{get_sibling(p)};
    auto parent{p->parent_};
    while (parent && !covers(sibling, q)) {
        sibling = get_sibling(parent);
        parent = parent->parent_;
    }
    return parent;
}

ctcilib::TreeNode<int>* common_ancestor_c_recurse(ctcilib::TreeNode<int>* root, ctcilib::TreeNode<int>* p, ctcilib::TreeNode<int>* q) {
    if (!root || root == p || root == q) {
        return root;
    }
    auto p_left{covers(root->left_, p)};
    auto q_left{covers(root->left_, q)};
    if (p_left != q_left) { // Nodes are on different side
        return root;
    }
    auto child_side{p_left ? root->left_ : root->right_};
    return common_ancestor_c_recurse(child_side, p, q);
}

ctcilib::TreeNode<int>* common_ancestor_c(ctcilib::TreeNode<int>* root, ctcilib::TreeNode<int>* p, ctcilib::TreeNode<int>* q) {
    /* Error check - one node is not in the tree */
    if (!covers(root, p) || !covers(root, q)) {
        return nullptr;
    }
    return common_ancestor_c_recurse(root, p, q);
}

struct Result {
    ctcilib::TreeNode<int>* node;
    bool is_ancestor;
};

Result common_ancestor_d_helper(ctcilib::TreeNode<int>* root, ctcilib::TreeNode<int>* p, ctcilib::TreeNode<int>* q) {
    if (!root) {
        return {root, false};
    }
    
    if (root == p && root == q) {
        return {root, true};
    }

    auto result_left{common_ancestor_d_helper(root->left_, p, q)};
    if (result_left.is_ancestor) { // Found common ancestor
        return result_left;
    }

    auto result_right{common_ancestor_d_helper(root->right_, p, q)};
    if (result_right.is_ancestor) { // Found common ancestor
        return result_right;
    }

    if (result_left.node && result_right.node) {
        return {root, true}; // This is the common ancestor
    } else if (root == p || root == q) {
        /* If we're currently at p or q, and we also found one of those nodes in a
         * subtree, then this is truly an ancestor and the flag should be true. */
        return {root, result_left.node || result_right.node};
    } else {
        return {result_left.node ? result_left.node : result_right.node, false};
    }
}

ctcilib::TreeNode<int>* common_ancestor_d(ctcilib::TreeNode<int>* root, ctcilib::TreeNode<int>* p, ctcilib::TreeNode<int>* q) {
    auto r{common_ancestor_d_helper(root, p, q)};
    return r.is_ancestor ? r.node : nullptr;
}

std::string result_to_string(std::string s, TreeNode<int>* x, TreeNode<int>* y, const TreeNode<int>* anc) {
		s += ": ";
		s += (x ? std::to_string(x->data_) : "null");
		s += " & ";
		s += (y ? std::to_string(y->data_) : "null");
		s += " -> ";
		s += (anc ? std::to_string(anc->data_) : "null");
		return s;
	}

int main() {
    std::vector<int> array{{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}};
    TreeNode<int> root(array);
    root.print();
    
    std::vector<TreeNode<int>*> nodes;
    for (int a : array) {
        nodes.push_back(root.find(a));
    }
    auto outside{std::make_shared<TreeNode<int>>(11)};
    nodes.push_back(outside.get());
    
    for (auto x : nodes) {
        for (auto y : nodes) {
            TreeNode<int>* r1{common_ancestor_a(x, y)};
            TreeNode<int>* r2{common_ancestor_b(x, y)};
            TreeNode<int>* r3{common_ancestor_c(&root, x, y)};
            TreeNode<int>* r4{common_ancestor_d(&root, x, y)};
            
            std::string s1{result_to_string("A", x, y, r1)};
            std::string s2{result_to_string("B", x, y, r2)};
            std::string s3{result_to_string("C", x, y, r3)};
            std::string s4{result_to_string("D", x, y, r4)};
            
            if (r1 == r2 && r2 == r3 && r3 == r4) {
                std::cout << "SUCCESS: " + s1 << std::endl;
            } else {
                std::cout << "ERROR" << std::endl;
                std::cout << s1 << std::endl;
                std::cout << s2 << std::endl;
                std::cout << s3 << std::endl;
                std::cout << s4 << std::endl;
            }
        }
    }
}