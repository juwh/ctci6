#pragma region Interview Question
/*
4.12 Paths with Sum: You are given a binary tree in which each node contains an integer value (which
might be positive or negative). Design an algorithm to count the number of paths that sum to a
given value. The path does not need to start or end at the root or a leaf, but it must go downwards
(traveling only from parent nodes to child nodes). 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#6. Try simplifying the problem. What if the path had to start at the root? 

#14. Don't forget that paths could overlap. For example, if you're looking for the sum 6, the
paths 1->3->2 and 1->3->2->4->-6->2 are both valid. 

#52. If each path had to start at the root we could traverse all possible paths starting from
the root. We can track the sum as we go, incrementing totalPaths each time we
find a path with our target sum. Now, how do we extend this to paths that can start
anywhere? Remember: Just get a brute-force algorithm done. You can optimize later. 

#68. To extend this to paths that start anywhere, we can just repeat this process for all nodes. 

#77. If you've designed the algorithm as described thus far, you'll have an O(N log N)
algorithm in a balanced tree. This is because there are N nodes, each of which is at depth
O(log N) at worst. A node is touched once for each node above it. Therefore, the N
nodes will be touched O(log N) time. There is an optimization that will give us an
O(N) algorithm. 

#87. What work is duplicated in the current brute-force algorithm? 

#94. Consider each path that starts from the root (there are N such paths) as an array. What
our brute-force algorithm is really doing is taking each array and finding all contiguous
subsequences that have a particular sum. We're doing this by computing all subarrays
and their sums. It might be useful to just focus on this little subproblem. Given an array,
how would you find all contiguous subsequences with a particular sum? Again, think
about the duplicated work in the brute-force algorithm. 

#103. We are looking for subarrays with sum targetSum. Observe that we can track in
constant time the value of runningSum_(i), where this is the sum from element 0 through
element i. For a subarray of element i through element j to have sum targetSum,
runningSum_(i-1) + targetSum must equal runningSum_(j) (try drawing a picture of
an array or a number line). Given that we can track the runningSum as we go, how can
we quickly look up the number of indices i where the previous equation is true? 

#108. Try using a hash table that maps from a runningSum value to the number of elements
with this runningSum. 

#115. Once you've solidified the algorithm to find all contiguous subarrays in an array with a
given sum, try to apply this to a tree. Remember that as you're traversing and modifying
the hash table, you may need to "reverse the damage" to the hash table as you traverse
back up. 
*/
#pragma endregion

#include <ctcilib/assorted_methods.h>
#include <ctcilib/TreeNode.h>

#include <algorithm>
#include <iostream>
#include <unordered_map>

/* Returns the number of paths with this sum starting from this node. */
size_t count_paths_with_sum_from_node(ctcilib::TreeNode<int>* node, int target_sum, int current_sum) {
    if (!node) {
        return 0;
    }

    current_sum += node->data_;
    
    int total_paths = 0;
    if (current_sum == target_sum) { // Found a path from the root
        ++total_paths;
    }
    
    total_paths += count_paths_with_sum_from_node(node->left_, target_sum, current_sum); // Go left
    total_paths += count_paths_with_sum_from_node(node->right_, target_sum, current_sum); // Go right
    
    return total_paths;
}

size_t count_paths_with_sum_naive(ctcilib::TreeNode<int>* root, int target_sum) {
    if (!root) {
        return 0; // Base case
    }

    /* Count paths with sum starting from the root. */
    size_t paths_from_root{count_paths_with_sum_from_node(root, target_sum, 0)};
    
    /* Try the nodes on the left and right. */
    size_t paths_on_left{count_paths_with_sum_naive(root->left_, target_sum)};
    size_t paths_on_right{count_paths_with_sum_naive(root->right_, target_sum)};
    
    return paths_from_root + paths_on_left + paths_on_right;
}

void increment_hash_table(std::unordered_map<int, int>& hash_table, int key, int delta) {
    int new_count{(hash_table.count(key) ? hash_table.at(key) : 0) + delta};
    if (!new_count) { // Remove when zero to reduce space usage
        hash_table.extract(key);
    } else {
        hash_table.insert({key, new_count});
    }
}

size_t count_paths_with_sum_hash(ctcilib::TreeNode<int>* node, int target_sum, int running_sum, std::unordered_map<int, int>& path_count) {
    if (!node) {
        return 0; // Base case
    }
    
    running_sum += node->data_;
    
    /* Count paths with sum ending at the current node. */
    int sum{running_sum - target_sum};
    int total_paths{path_count.count(sum) ? path_count.at(sum) : 0};
    
    /* If runningSum equals targetSum, then one additional path starts at root. Add in this path.*/
    if (running_sum == target_sum) {
        ++total_paths;
    }

    /* Add runningSum to pathCounts. */
    increment_hash_table(path_count, running_sum, 1);
    
    /* Count paths with sum on the left and right. */
    total_paths += count_paths_with_sum_hash(node->left_, target_sum, running_sum, path_count);
    total_paths += count_paths_with_sum_hash(node->right_, target_sum, running_sum, path_count);
    
    increment_hash_table(path_count, running_sum, -1); // Remove runningSum
    return total_paths;
}

size_t count_paths_with_sum(ctcilib::TreeNode<int>* root, int target_sum) {
    std::unordered_map<int, int> hash_map;
    return count_paths_with_sum_hash(root, target_sum, 0, hash_map);
}

int main() {
    int min{-20};
    int max{20};
    int size{20};
    ctcilib::TreeNode<int> root{ctcilib::random_bst(size, min, max)};

    for (int target_sum = std::min(-1, min * size - 10); target_sum <= std::max(100, max * size + 10); target_sum++) {
        size_t answer_A{count_paths_with_sum_naive(&root, target_sum)};
        size_t answer_B{count_paths_with_sum(&root, target_sum)};
        if (answer_A > 0 || answer_B > 0) {
            std::cout << std::to_string(target_sum) + ": " + std::to_string(answer_A) + ", " + std::to_string(answer_B) + " | " + std::to_string(answer_A == answer_B) << std::endl;
        }
        if (answer_A != answer_B) {
            break;
        }
    }
}