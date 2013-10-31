/**
Binary Tree Maximum Path Sum

 Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3

Return 6. 
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
    int maxPathSum(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int csum = 0;
        int maxsum = INT_MIN;
        maxPath(root, csum, maxsum);
        return maxsum;
    }
    
    void maxPath(TreeNode *root, int&csum, int &maxsum){
        if (!root){
            csum =0;
            return;
        }
        int lsum = 0;
        int rsum = 0;
        maxPath(root->left, lsum, maxsum);
        maxPath(root->right, rsum, maxsum);
        csum = max(root->val, max(lsum + root->val, rsum + root->val));
        maxsum = max(maxsum, max(csum, root->val + lsum + rsum));
    }
};