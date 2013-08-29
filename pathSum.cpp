/**
 * Definition for binary tree
 * struct TreeNode {
 *       int val;
 *       TreeNode *left;
 *       TreeNode *right;
 *       TreeNode(int x): val(x), left(NULL), right(NULL) {}
 *   };
 *
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum
 */
vector<vector<int>> pathSum(TreeNode *root, int sum){
    vector<vector<int>> out;
    if (root==NULL) return out;

    stack<TreeNode*> st;
    TreeNode *top, *child, *father;
    vector<int> vt;
    int stsum = 0;

    st.push(root);
    vt.push_back(root->val);
    stsum = root->val;

    while(!st.empty()){
        top = st.top();
        if(top->left)
        {
            st.push(top->left);
            stsum += top->left->val;
            vt.push_back(top->left->val);
        }else if(top->right){
            st.push(top->right);
            stsum += top->right->val;
            vt.push_back(top->right->val);
        }else{
            if (stsum == sum)
                out.push_back(vt);
            child = top;
            st.pop();
            vt.pop_back();
            stsum -= child->val;

            while(!st.empty()){
                father = st.top();
                if(father->left == child && father->right == NULL || father->right == child)
                {
                    child = father;
                    st.pop();
                    vt.pop_back();
                    stsum -= child->val;
                }else{
                    st.push(father->right);
                    vt.push_back(father->right->val);
                    stsum += father->right->val;
                    break;
                }
            }
        }
    }
    return out;
}
