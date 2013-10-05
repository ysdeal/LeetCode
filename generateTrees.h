/**
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

*/
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
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
    vector<TreeNode *> generateTrees(int n) {
        return generateTrees(1,n);
    }

    vector<TreeNode *> generateTrees(int s, int t){
         vector<TreeNode*> res;
        if(s > t){
            res.push_back(NULL);
            return res;
        }
        
       
        for(int i = s; i <= t; i++){
            vector<TreeNode*> leftsub = generateTrees(s, i-1);
            vector<TreeNode*> rightsub = generateTrees(i+1, t);
            for(int j = 0; j < leftsub.size(); j++){
                for(int k = 0; k < rightsub.size(); k++){
                    TreeNode *root = new TreeNode(i);
                    root->left = leftsub[j];
                    root->right = rightsub[k];
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};