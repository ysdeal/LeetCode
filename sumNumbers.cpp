/**
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3

The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25
 * Definition for binary tree
 * struct TreeNode {
 *   int val;
 *   TreeNode *left;
 *   TreeNode *right;
 *   TreeNode(int x): val(x), left(NULL), right(NULL){};
 *   };
*/
/* iterative solution: traveral order */
int sumNumbers(TreeNode *root){
    if (root==NULL)
        return 0;

    int sum = 0;
    int rootval = 0;
    TreeNode *parent, *child, *top;
    stack<TreeNode*> st;
    st.push(root);
    top = root;
    rootval = root->val;
    while(!st.empty()){
        top = st.top();
        if(top->left){
            st.push(top->left);
            rootval *= 10;
            rootval += top->left->val;
        }else if(top->right){
            st.push(top->right);
            rootval *= 10;
            rootval += top->right->val;
        }else{
            sum += rootval;
            child = top;
            st.pop();
            rootval -= top->val;
            rootval /= 10;

            while(!st.empty()){
                 parent = st.top();
                 if(parent->left == child && parent->right==NULL || parent->right == child){
                     child = parent;
                     st.pop();
                     rootval -= child->val;
                     rootval /= 10;
                 }else{
                     st.push(parent->right);
                     rootval *= 10;
                     rootval += parent->right->val;
                     break;
                 }
            }
        }
    }
    return sum;
}

/* recursive verison */
int psumNumbers(TreeNode* root, int psum, int sum)
{
    if(!root)
      return 0;
    psum = psum*10 + root->val;
    if (root->left==NULL && root->right==NULL)
      return psum + sum;
    
    if (root->left)
       sum = psumNumbers(root->left, psum , sum);
    if (root->right)
       sum = psumNumbers(root->right, psum, sum);
    
    return sum;
}
int sumNumbers(TreeNode *root){
    return psumNumbers(root, 0, 0);
}
