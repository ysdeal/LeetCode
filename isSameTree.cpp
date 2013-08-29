/**
 * Definition of binary tree
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode(int x): val(x), left(NULL), right(NULL) {};
 * };
 */

bool isSameTree(TreeNode*p, TreeNode *q){
     if(p==NULL && q == NULL)
        return true;
                     
     if(!(p&&q))
        return false;
                            
     if(p->val!=q->val)
        return false;
     return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
}

