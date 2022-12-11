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

//fn def
node* flatten(node* root) {

	//curr replicates root and traverses 
	node* curr = root;

	//till curr is not NULL
	while (curr != NULL) {

		//if curr left exists
		if (curr->left) {

			//make predecessor as cuur -> left
			node* pred = curr->left;

			//make pred to the rightmost node  ( whose right->NULL)
			while (pred->right) {
				pred = pred->right;
			}
			//now pred->right = NULL


			//reconnect pred right to curr -> right
			pred->right = curr->right;

			//remove curr-> right to curr-> left
			curr->right = curr->left;
			//make curr-> left = NULL
			curr->left = NULL;

		}

		//update curr to traverse whole tree
		curr = curr->right;

	}

	//returns root of flattened tree
	return root;

}





int main() {

	node* root = NULL;

	buildTree(root);

	flatten(root);

	cout << endl;

	leveltraversal(root);

	return 0;
}