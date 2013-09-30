/** 
Given preorder and inorder traversal of a tree, construct the binary tree.

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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = preorder.size();
        if(n==0) return NULL;
        
        return buildBT(preorder,inorder, 0, 0, n - 1);
    }
private:
   TreeNode *buildBT(vector<int> &preorder, vector<int> &inorder, 
             int pos, int start, int end){
        if(start > end) return NULL;
        int j = std::find(inorder.begin()+start, inorder.begin()+end,
                preorder[pos]) - inorder.begin();
        TreeNode *root = new TreeNode(preorder[pos]);
        root->left = buildBT(preorder,inorder,pos+1,start, j-1);
        root->right = buildBT(preorder,inorder,j+pos-start+1,j+1,end);
        return root;
    }
};