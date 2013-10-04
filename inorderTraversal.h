/**
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3

return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> inorderTraversal(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        stack<TreeNode*> st;
        st.push(root);
        vector<int> out;
        if(!root) return out;
        TreeNode *top;
        TreeNode *par;
        TreeNode *chi;
        
        while(!st.empty()){
            top = st.top();
            if(top->left){
                st.push(top->left);
                continue;
            }else{
                out.push_back(top->val);
                st.pop();
                chi = top;
                if(top->right)
                  st.push(top->right);
                else{
                    while(!st.empty()){
                        par = st.top();
                        if(par->left == chi || (par->right != chi || par->right != chi)){
                            chi = par;
                            out.push_back(par->val);
                            st.pop();
                        }
                        if (par->right){
                            st.push(par->right);
                            break;
                        }
                        
                    }
                }
            }
        
        }
        return out;
    }
};
