/**
 Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6

The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

click to show hints.
Hints:

If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.

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
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeNode *temp = NULL;
        postOrder(root, temp);
    }
private:
     void postOrder(TreeNode *root, TreeNode *&temp){
        if(root){
            postOrder(root->right, temp);
            postOrder(root->left, temp);
            root->right = temp;
            temp = root;
            root->left = NULL;
        }
     }
};