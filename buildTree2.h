/** 
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree. 
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = inorder.size();
        if(n==0) return NULL;
        
        return buildBT(inorder, postorder, n-1, 0, n-1);
    }
private:
    TreeNode *buildBT(vector<int> &inorder, vector<int> &postorder, int pos, int start, int end){
        if(start > end) return NULL;
        TreeNode *root = new TreeNode(postorder[pos]);
        int j = std::find(inorder.begin()+start,inorder.begin()+end, postorder[pos]) - inorder.begin();
        root->left = buildBT(inorder, postorder, pos-1-end+j, start, j-1);
        root->right = buildBT(inorder,postorder,pos-1,j+1,end);
        return root;
    }
};