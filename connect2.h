/**
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

    You may only use constant extra space.

For example,
Given the following binary tree,

         1
       /  \
      2    3
     / \    \
    4   5    7

After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
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
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
         if(root==NULL) return;
        
        vector<TreeLinkNode*> nodelist;
        nodelist.push_back(root);
        
        while(!nodelist.empty()){
            int len = nodelist.size();
            for(int j = 0; j < len-1; j++){
                  nodelist[j]->next = nodelist[j+1];
                  if(nodelist[j]->left) nodelist.push_back(nodelist[j]->left);
                  if(nodelist[j]->right) nodelist.push_back(nodelist[j]->right);
            }
            nodelist[len-1]->next = NULL;
            if(nodelist[len-1]->left) nodelist.push_back(nodelist[len-1]->left);
            if(nodelist[len-1]->right) nodelist.push_back(nodelist[len-1]->right);
            nodelist.erase (nodelist.begin(),nodelist.begin()+len);
        }
        return;       
    }
};