/** 
 Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.
Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

OJ's Binary Tree Serialization:

The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:

   1
  / \
 2   3
    /
   4
    \
     5

The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}". 
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
    void recoverTree(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<TreeNode*> list;
        vector<int> vals;
        if(!root) return;
        inOrderTra(root,list,vals);
        sort(vals.begin(), vals.end());
        for(int i = 0; i < list.size(); i++)
          list[i]->val = vals[i];
        return;
    }
private:
    void inOrderTra(TreeNode *root, vector<TreeNode*> &list, vector<int> &vals){
        if(!root) return;
        inOrderTra(root->left,list,vals);
        list.push_back(root);
        vals.push_back(root->val);
        inOrderTra(root->right, list, vals);
        return;
        }
};