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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> out;
        traverse(root,1,out);
        reverse(out.begin(),out.end());
        return out;
        
    }
private:
   void traverse(TreeNode*root, int level, vector<vector<int> > &res)
   {
       if(!root) return;
       
       if(level>res.size()){
           vector<int> temp;
           res.push_back(temp);
       }
       res[level-1].push_back(root->val);
       traverse(root->left,level+1,res);
       traverse(root->right,level+1,res);
   }
};