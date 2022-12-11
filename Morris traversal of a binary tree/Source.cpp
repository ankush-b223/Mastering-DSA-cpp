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



void morrisTraversal(node* root) {

	//initializing req objects
	node* curr = root;
	node* pred;

	//underflow .. > tree is empty
	if (root == NULL) {
		return;
	}


	//till curr becomes NULL
	while (curr != NULL) {

		//if curr left doesn't exist >> print & move curr to its right
		if (curr->left == NULL) {
			cout << curr->data << " ";
			curr = curr->right;
		}

		//curr-> left exists
		else {

			//initially appoint predecessor as curr-> left
			pred = curr->left;

			//run a loop
			//it runs till it finds a pred whose right is null  OR a pred whose right is curr
			while (pred->right != NULL && pred->right != curr) {

				pred = pred->right;

			}

			//if(pred-> right == NULL
			if (pred->right == NULL) {
				//create temporary link 
				pred->right = curr;
				//update curr
				curr = curr->left;
			}
			//else remove temporary link
			//print node
			else {

				//remove temporary link
				pred->right = NULL;
				//print node
				cout << curr->data << " ";
				//update curr
				curr = curr->right;

			}


		}
		

	}


}









int main() {


	node* root = NULL;

	buildTree(root);

	cout << endl;

	morrisTraversal(root);

	return 0;
}