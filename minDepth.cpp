/**
 * Definition of binary tree
 * struct TreeNode{
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x): val(x), left(NULL), right(NULL) {};
 *     }
 */

int minDepth(TreeNode *root){
    if(root==NULL) return 0;

    if (root->left==NULL&& root->right==NULL)
        return 1;
    int l = minDepth(root->left);
    int r = minDepth(root->right);
    if (l==0)
        return 1+r;
    else if(r==0)
        return 1+l;

    return 1+min(r,l);
}
