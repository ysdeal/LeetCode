/*
 *Given a binary tree, determine if it is height-balanced.

 *For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int lh, rh;
        if (!root)
           return true;
        lh = treeHeight(root->left);
        rh = treeHeight(root->right);
        if(abs(lh-rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
          return true;

        return false;
    }
private:
    int treeHeight(TreeNode *root){
        if (!root)
           return 0;
        return 1+max(treeHeight(root->left),treeHeight(root->right));
    }
};