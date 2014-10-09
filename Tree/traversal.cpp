#include <iostream>
#include <stack>

using namespace std;

class TreeNode
{
public:
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
	int val;
	TreeNode *left;
	TreeNode *right;
};

// recursive version
void preOrder(TreeNode *root){
	if(root == nullptr)
		return;
	cout << root->val << "=>";
	preOrder(root->left);
	preOrder(root->right);
}

// iterative version of preorder
void preOrderIter(TreeNode *root){
	if(root == nullptr)
		return;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
    	root = st.top();
    	st.pop();
    	cout << root->val << "=>";
    	if(root->right)
    		st.push(root->right);
    	if(root->left)
    		st.push(root->left);
    }
}


void preOrderMorris(TreeNode *root){
	if(root == nullptr)
		return;
	while(root){
		if(root->left == nullptr){
			cout << root->val << "=>";
			root = root->right;
		}else{
			TreeNode *cur = root->left;
			while(cur->right && cur->right != root)
				cur = cur->right;
			if(cur->right == nullptr){
				cur->right = root;
				cout << root->val << "=>";
				root = root->left;
			}else{
				root = root->right;
				cur->right = nullptr;
			}
		}
	}
}

// recursive version of inOrder
void inOrder(TreeNode *root){
    if(root == nullptr)
    	return;
    inOrder(root->left);
    cout << root->val << "=>";
    inOrder(root->right);
}

// iterative version of inOrder
void inOrderIter(TreeNode *root){
	if(root == nullptr)
		return;
	stack<TreeNode*> st;
	while(!st.empty() || root){
		if(root == nullptr){
			root = st.top();
			st.pop();
			cout << root->val << "=>";
			root = root->right;
		}else{
			st.push(root);
			root = root->left;
		}
	}
}

// Morris version
void inOrderMorris(TreeNode *root){
	if(root == nullptr)
		return;
	while(root){
		if(root->left == nullptr){
			cout << root->val << "=>";
			root = root->right;
		}else{
			TreeNode *cur = root->left;
			while(cur->right && cur->right != root)
				cur = cur->right;
			if(cur->right == nullptr){
				cur->right = root;
				root = root->left;
			}else{
				cur->right = nullptr;
				cout << root->val << "=>";
				root = root->right;
			}
		}
	}
}

// postOder
void postOrder(TreeNode *root){
	if(root == nullptr)
		return;
	postOrder(root->left);
	postOrder(root->right);
	cout << root->val << "=>";
}

void postOrderIter(TreeNode *root){
	if(root == nullptr)
		return;
	stack<TreeNode*> st;
	TreeNode *last = nullptr;
	TreeNode *top;
	while(!st.empty() || root){
		if(root){
			st.push(root);
			root = root->left;
		}else{
            top = st.top();
            if(top->right && last != top->right)
            	root = top->right;
            else{
            	cout << top->val << "=>";
            	st.pop();
            	last = top;
            }
		}
	}
}

void reverse(TreeNode *from , TreeNode *to){
	if(from == to)
		return;
	TreeNode *x = from, *y = from->right, *z;
	while(true){
		z = y->right;
		y->right = x;
		x = y;
		y = z;
		if(x == to)
			break;
	}
}

void printRev(TreeNode *from, TreeNode *to){
	reverse(from, to);
	TreeNode *p = to;
	while(true){
		cout << p->val << "=>";
		if(p == from)
			break;
		p = p->right;
	}
    reverse(to,from);
}

// postOrder Morris
void postOrderMorris(TreeNode *root){
	TreeNode dummy(0);
	dummy.left = root;
	TreeNode *cur = &dummy;
	while(cur){
		if(cur->left == nullptr)
			cur = cur->right;
		else{
			TreeNode *prev = cur->left;
			while(prev->right && prev->right != cur)
				prev = prev->right;
			if(prev->right == nullptr){
				prev->right = cur;
				cur = cur->left;
			}else{
                 printRev(cur->left, prev);
                 prev->right = nullptr;
                 cur = cur->right;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	TreeNode *root = new TreeNode(30);
    root->left        = new TreeNode(15);
    root->right       = new TreeNode(38);
    root->left->left  = new TreeNode(10);
    root->left->right = new TreeNode(20);
    root->right->left = new TreeNode(36);
    root->right->right = new TreeNode(41);
    root->right->right->right = new TreeNode(50);
    cout << "Inorder Rec" << endl;
    inOrder(root), cout << endl;
    cout << "Inorder Iter" << endl;
    inOrderIter(root), cout << endl;
    cout << "Inorder Morris" << endl;
    inOrderMorris(root), cout << endl;

    cout << "Preorder Rec" << endl;
    preOrder(root), cout << endl;
    cout << "Preorder Iter" << endl;
    preOrderIter(root), cout << endl;
    cout << "Preorder Morris" << endl;
    preOrderMorris(root), cout << endl; 

    cout << "Postorder Rec" << endl;
    postOrder(root), cout << endl;
    cout << "Postorder Iter" << endl;
    postOrderIter(root), cout << endl; 
    cout << "Postorder Morris" << endl;
    postOrderMorris(root), cout << endl;   
	return 0;
}