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

int height(TreeNode *root){
	if(root == nullptr)
		return 0;
	return root->height;
}

int getBalance(TreeNode *root){
	if(root == nullptr)
		return 0;
	return height(root->left) - height(root->right);
}

TreeNode *getMinValueNode(TreeNode *root){
	if(root == nullptr)
		return root;
	while(root->left != nullptr)
		root = root->left;
	return root;
}

/* right rotate subtree rooted with root
T1, T2 and T3 are subtrees of the tree rooted with y (on left side) 
or x (on right side)           
                y                               x
               / \     Right Rotation          /  \
              x   T3   – - – - – - – >        T1   y 
             / \       < - - - - - - -            / \
            T1  T2     Left Rotation            T2  T3
Keys in both of the above trees follow the following order 
      keys(T1) < key(x) < keys(T2) < key(y) < keys(T3)
So BST property is not violated anywhere.
*/

TreeNode *rightRotate(TreeNode *y){
     TreeNode *x = y->left;
     TreeNode *T2 = x->right;

     // perform rotation
     x->right = y;
     y->left = T2;

     // Update heights
     y->height = max(height(y->left), height(y->right)) + 1;
     x->height = max(height(x->left), height(x->left)) + 1; 
     return x;
}

TreeNode *leftRotate(TreeNode *x){
	TreeNode *y = x->right;
	TreeNode *T2 = y->left;
	y->left = x;
	x->right = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->left)) + 1;
    return y;
}

TreeNode *insert(TreeNode *root, int key){
	if(root == nullptr)
		return new TreeNode(key);
	if(key < root->val)
		root->left = insert(root->left, key);
	else if(key == root->val)
		return root;
	else
		root->right = insert(root->right, key);

	root->height = max(height(root->left), height(root->right)) + 1;
	int balance = getBalance(root);
    
    /* LEFT LEFT
    T1, T2, T3 and T4 are subtrees.
         z                                      y 
        / \                                   /   \
       y   T4      Right Rotate (z)          x      z
      / \          - - - - - - - - ->      /  \    /  \ 
     x   T3                               T1  T2  T3  T4
    / \
  T1   T2
  */
	if(balance > 1 && key < root->left->val)
		return rightRotate(root);
	/* LEFT RIGHT
     z                               z                           x
    / \                            /   \                        /  \ 
   y   T4  Left Rotate (y)        x    T4  Right Rotate(z)    y      z
  / \      - - - - - - - - ->    /  \      - - - - - - - ->  / \    / \
T1   x                          y    T3                    T1  T2 T3  T4
    / \                        / \
  T2   T3                    T1   T2
  */
	if(balance > 1 && key > root->left->val){
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	/*RIGHT LEFT
   z                            z                            x
  / \                          / \                          /  \ 
T1   y   Right Rotate (y)    T1   x      Left Rotate(z)   z      y
    / \  - - - - - - - - ->     /  \   - - - - - - - ->  / \    / \
   x   T4                      T2   y                  T1  T2  T3  T4
  / \                              /  \
T2   T3
*/
    if(balance < -1 && key < root->right->val){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    /* RIGHT RIGHT
  z                                y
 /  \                            /   \ 
T1   y     Left Rotate(z)       z      x
    /  \   - - - - - - - ->    / \    / \
   T2   x                     T1  T2 T3  T4
       / \
     T3  T4
 */  
    if(balance < -1 && key > root->right->val)
       return leftRotate(root);	   
    return root;
}

TreeNode *deleteNode(TreeNode *root, int key){
	if(root == nullptr)
		return root;
	if(key < root->val)
		root->left = deleteNode(root->left, key);
	else if (key > root->val)
		root->right = deleteNode(root->right, key);
	else{
		if(root->left == nullptr || root->right == nullptr){
			TreeNode *temp = (root->left == nullptr)?root->right:root->left;
			if(temp == nullptr){
				temp = root;
				root = nullptr;
			}else
			   *root = *temp;
		    delete temp;
		}else{
			TreeNode *temp = getMinValueNode(root->right);
			root->val = temp->val;
			root->right = deleteNode(root->right, temp->val);
		}
	}
	if(root == nullptr)
		return root;

	//update height
	root->height = max(height(root->left),height(root->right)) + 1;
	int balance = getBalance(root);
	if(balance > 1 && getBalance(root->left) >= 0)
		return rightRotate(root);
	if(balance > 1 && getBalance(root->left) < 0){
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	if(balance < -1 && getBalance(root->right) >= 0){
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	if(balance < -1 && getBalance(root->right) < 0)
		return leftRotate(root);
	return root;
}

void preOrder(TreeNode *root){
	if(root == nullptr)
		return;
	cout << root->val << " ";
	preOrder(root->left);
	preOrder(root->right);
}

int main(int argc, char const *argv[])
{
	  TreeNode *root = nullptr;
  /* Constructing tree given in the above figure */
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);
	cout << "preOrder traversal of the constructed AVL tree is " << endl;
	preOrder(root);
	cout << endl;
	cout << "preOrder traversal of the constructed AVL tree after deletion is " << endl;
	preOrder(deleteNode(root, 10));
	cout << endl;
	return 0;
}