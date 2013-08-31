 /**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
     vector<vector<int> > out;
     if (!root) return out;
      bool flag = true;
      vector<TreeNode*> nodelist;
      vector<TreeNode*> nextlevel;
      nodelist.push_back(root);
      while(!nodelist.empty()){
          vector<int> temp;
          int len = nodelist.size();
          
          for(int i=len-1;i>=0;i--){
                TreeNode* t = nodelist[i];
                temp.push_back(t->val);
                if(flag){
                     if(t->left) nextlevel.push_back(t->left);
                     if(t->right) nextlevel.push_back(t->right);
                }else{
                     if(t->right) nextlevel.push_back(t->right);
                     if(t->left) nextlevel.push_back(t->left);  
                    }
                }
          nodelist.swap(nextlevel);
          nextlevel.clear();
          flag = !flag;
          out.push_back(temp);
      }
    return out;
}