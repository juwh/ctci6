#ifndef TREENODE_H_
#define TREENODE_H_

#include <vector>

namespace ctcilib {
    /* One node of a binary tree. The data element stored is a single 
    * character.
    */
    template<typename T>
    class TreeNode {
        private:
            size_t m_size{};
            void setLeftChild(TreeNode left);
            void setRightChild(TreeNode right);
            static TreeNode<T> createMinimalBST(std::vector< T > arr, int start, int end);
        public:
            T data{};
            TreeNode* m_left;
            TreeNode* m_right;
            TreeNode* m_parent;
            TreeNode(T d);
            void insertInOrder(T d);
            size_t size() const;
            bool isBST() const;
            size_t height() const;
            TreeNode<T>& find(T d) const;
            static TreeNode<T> createMinimalBST(std::vector< T > array);
            void print() const;
    };
}
#endif // TREENODE_H_