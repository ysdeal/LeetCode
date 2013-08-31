 /**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    vector<vector<int> > out;
    if(root==NULL) return out;
    
    vector<TreeNode*> nodelist;
    nodelist.push_back(root);
    while(!nodelist.empty()){
        vector<int> temp;
        int len = nodelist.size();
        for(int i=0;i<len;i++)
        {
           temp.push_back(nodelist[i]->val);
           if(nodelist[i]->left)
             nodelist.push_back(nodelist[i]->left);
           if(nodelist[i]->right)
             nodelist.push_back(nodelist[i]->right);
        }   
        out.push_back(temp);
        nodelist.erase(nodelist.begin(),nodelist.begin()+len);
        cout<< nodelist.size()<<" ";
		//break;
    }
    return out;
 }