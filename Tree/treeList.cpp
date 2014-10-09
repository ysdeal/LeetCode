#include <algorithm>
#include <iostream>

using namespace std;

class TreeNode{
public:
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

// convert to list
void convertToList(TreeNode *root, TreeNode *&head){
	if(root == nullptr)
		return;
	static TreeNode *pre = nullptr;
	convertToList(root->left, head);
	if(pre == nullptr)
		head = root;
	else{
		pre->right = root;
		root->left = pre;
	}
	pre = root;
    convertToList(root->right, head);
}

// convert to tree
TreeNode *convertToTreeHelper(TreeNode *&root, int s, int e){
    if(s > e)
    	return nullptr;
    int m = (e - s)/2 + s;
    TreeNode *left = convertToTreeHelper(root, s, m - 1);
    TreeNode *cur = root;
    cur->left = left;
    root = root->right;
    cur->right = convertToTreeHelper(root, m+1, e);
    return cur;
}

// print list
void printList(TreeNode *head){
	while(head != nullptr){
		cout << head->val << "==>";
		head = head->right;
	}
}

void inOrder(TreeNode *root){
	if(root == nullptr)
		return;
    inOrder(root->left);
    cout << root->val << "==>";
    inOrder(root->right);
}

int main(int argc, char const *argv[])
{
	TreeNode *root = new TreeNode(10);
    root->left        = new TreeNode(12);
    root->right       = new TreeNode(15);
    root->left->left  = new TreeNode(25);
    root->left->right = new TreeNode(30);
    root->right->left = new TreeNode(36);
    root->right->right = new TreeNode(41);
    root->right->right->right = new TreeNode(50);
    inOrder(root);
    cout << endl;
    TreeNode *head = nullptr;
    convertToList(root, head);
    printList(head);
    cout << endl;
    TreeNode *second = convertToTreeHelper(head, 0, 7);
    inOrder(second);
	return 0;
}