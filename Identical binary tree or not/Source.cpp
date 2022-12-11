#include<iostream>
#include<queue>
using namespace std;


class node {

public:

	int data;
	node* left;
	node* right;

	node(int d) {
		this->data = d;
		this->left = NULL;
		this->right = NULL;
	}

};

node* buildTree(node*& root) {

	cout << "Enter data " << endl;
	int data;
	cin >> data;

	root = new node(data);

	if (root->data == -1) {
		return NULL;
	}

	cout << "Enter data to be inserted in the left of " << root->data << endl;
	root->left = buildTree(root->left);

	cout << "Enter data to be inserted in the right of " << root->data << endl;
	root->right = buildTree(root->right);

	return root;

}

void levelOrderTraversal(node*& root) {

	queue<node*> q;

	if (root == NULL) {
		cout << "tree is empty" << endl;
		return;
	}

	q.push(root);
	q.push(NULL);

	while (!q.empty()) {

		node* temp = q.front();
		q.pop();

		if (temp == NULL) {
			cout << endl;

			if (!q.empty()) {
				q.push(NULL);
			}
		}

		else {

			cout << temp->data << " ";

			if (temp->left) {
				q.push(temp->left);
			}

			if (temp->right) {
				q.push(temp->right);
			}

		}


	}


}

//fn def
bool isIdentical(node* root1, node* root2) {

	//move both roots together

	//base case(s)
	if (root1 == NULL && root2 == NULL) {
		return true;
	}

	if (root1 == NULL && root2 != NULL){
		return false;
	}

	if (root1 != NULL && root2 == NULL) {
		return false;
	}

	//recursive calls
	bool left = isIdentical(root1->left, root2->left);
	bool right = isIdentical(root1->right, root2->right);

	//check if both nodes have same data
	bool data = root1->data == root2->data;

	//if all condn true returnh true else false
	if (left && right && data) {
		return true;
	}
	else{
		return false;
	}

}


int main() {

	node* root = NULL;
	buildTree(root);

	cout << "tree 1 " << endl;
	
	levelOrderTraversal(root);
	cout << endl;

	
	
	node* root2 = NULL;
	buildTree(root2);

	cout << "tree 2 " << endl;

	levelOrderTraversal(root2);
	cout << endl;


	if (isIdentical(root, root2)) {
		cout << "Identical" << endl;
	}
	else {
		cout << "Not identical"  <<endl;
	}

	return 0;
}