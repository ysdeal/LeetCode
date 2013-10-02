/**
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = num.size();
        
        return arrayToBST(num,0,n-1);
    }
    
    TreeNode *arrayToBST(vector<int> &num, int st, int ed){
        if(st > ed) return NULL;
        int m = st + (ed - st) / 2;
        TreeNode *lf = arrayToBST(num,st,m-1);
        TreeNode *p = new TreeNode(num[m]);
        p->left = lf;
        p->right = arrayToBST(num,m+1,ed);
        return p;
    }
};