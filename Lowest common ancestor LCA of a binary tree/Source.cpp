#include<iostream>
#include<queue>
#include<map>
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

	cout << "Enter data" << endl;
	int d;
	cin >> d;

	root = new node(d);

	if (root->data == -1) {
		return NULL;
	}


	cout << "enter element to be inserted in the left of " << root->data << endl;
	root->left = buildTree(root->left);

	cout << "enter element to be inserted in the right of " << root->data << endl;
	root->right = buildTree(root->right);


	return root;


}

void leveltraversal(node* root) {

	queue<node*>q;

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




node* lca(node* root,int n1,int n2) {

	//base case
	if (root == NULL) {
		return NULL;
	}

	//if any node required is found
	if (root->data == n1 || root->data == n2) {
		return root;
	}

	//recursive calls to left & right
	node* leftAns = lca(root->left, n1, n2);
	node* rightAns = lca(root->right, n1, n2);

	//if both calls return yes node found return the root as answer
	if (leftAns != NULL && rightAns != NULL) {
		return root;
	}

	//if none is found return null
	else if (leftAns == NULL && rightAns == NULL) {
		return NULL;
	}
	//if one is found return its node
	else if (leftAns != NULL && rightAns == NULL) {
		return leftAns;
	}
	else if (leftAns == NULL && rightAns != NULL) {
		return rightAns;
	}

	else {
		return NULL;
	}


}


int main() {

	node* root = NULL;

	buildTree(root);

	node* ans = lca(root, 3,4);


	cout << ans->data << endl;


	return 0;
}