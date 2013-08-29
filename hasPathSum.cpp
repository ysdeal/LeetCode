/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x):val(x), left(NULL), right(NULL) {}
 *  };
 */

bool hasPathSum(TreeNode *root, int num){
    if(root==NULL)
        return false;
    if(sum==root->val && !(root->left || root->right))
        return true;
    else
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}
