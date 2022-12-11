#include <iostream>
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

node* insertBST(node* root, int d) {

	if (root == NULL) {
		root = new node(d);
		return root;
	}

	if (root->data > d) {

		root->left = insertBST(root->left,d);
	}
	else {
		root->right = insertBST(root->right, d);
	}

	return root;

}


void takeInput(node*& root) {

	cout <<" Enter data " << endl;
	int d;
	cin >> d;

	while (d != -1) {
		root = insertBST(root, d);
		cin >> d;
	}

}



void levelTraversal(node* root) {

	if (root == NULL) {
		return;
	}
	
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

//max fn
//takes range of root's data in args as>> min & max
bool solve(node* root, int min, int max) {

	//base case
	if (root == NULL) {
		return true;
	}

	//if range fullfilled
	if (root->data >= min && root->data <= max) {
		//check left 
		//when going left range becomes -infinity , root data
		bool left = solve(root->left, min, root->data);
		//when going right range becomes root data , positive infinity
		bool right = solve(root->right, root->data, max);

		//if both left & right fullfill or true >> return true
		if (left && right) {
			return true;
		}


	}
	//else
	return false;

}

//result returning fn
bool isBST(node* root) {

	//for root node range is negative infinity , positive infinity 
	//so intMIn intMAx as infinity
	return solve(root, INT_MIN, INT_MAX);

}













int main() {

	node* root = NULL;

	takeInput(root);

	cout << endl;

	levelTraversal(root);



	return 0;

}