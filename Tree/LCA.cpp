#include <algorithm>
#include <iostream>

#define max(a,b) (a > b ? a : b)
using namespace std;

class TreeNode{
public:
	int val;
	TreeNode *left;
	TreeNode *right;
	int height;
	TreeNode(int x):val(x),left(nullptr),right(nullptr), height(1){}
};

TreeNode *LCA(TreeNode *root, TreeNode *q, TreeNode *p){
	if(root == nullptr)
		return root;
	if(root == q || root == p)
		return root;
	TreeNode *left = LCA(root->left, q, p);
	TreeNode *right = LCA(root->right, q, p);
	if(left != nullptr && right != nullptr)
		return root;
	return (left != nullptr)?left:right;
}

int main(int argc, char const *argv[])
{
	TreeNode *root = new TreeNode(5);
	root->left = new TreeNode(3);
	root->right = new TreeNode(8);
	root->left->left = new TreeNode(1);
	root->right->left = new TreeNode(7);
	TreeNode *ans = LCA(root, root->left->left, root->left);
	cout << ans->val << endl;
	return 0;
}