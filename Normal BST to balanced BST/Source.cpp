#include <iostream>
#include<vector>
using namespace std;


class node {

public:

	int data;
	node* left = NULL;
	node* right = NULL;


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
		root->left = insertBST(root->left, d);
	}
	else {
		root->right = insertBST(root->right, d);
	}

	return root;
}



void takeInput(node*& root) {

	cout << "Enter data " << endl;

	int d;

	cin >> d;

	while (d != -1) {
		root = insertBST(root, d);
		cin >> d;

	}

}

//making inorder vector fn def
void makeInorder(node* root, vector<int> &inOrder) {

	if (root == NULL) {
		return;
	}

	makeInorder(root->left, inOrder);
	inOrder.push_back(root->data);
	makeInorder(root->right, inOrder);

}

//main fn
node* balanced( int start, int end, vector<int> inOrder) {

	//base case
	if (start > end) {
		return NULL;
	}


	//fetch mid data from inorder vector
	int mid = (start + end) / 2;

	//make a new node with mid's data
	//also the root of balanced BST
	node* newRoot = new node(inOrder[mid]);

	//call for left & right with binary search logic
	//for left the range would be     start -> mid-1 
	//for right range is   mid+1 -> end
	newRoot->left = balanced( start, mid-1,inOrder);
	newRoot->right = balanced( mid+1, end,inOrder);

	//return balnced bst root
	return newRoot;

}

//answer returning fn
node* toBalancedBST(node* root) {

	//create vector to store inorder of given tree
	vector<int> inOrder;
	//make inorder vector
	makeInorder(root, inOrder);

	//call for result root which has a balanaced bst
	node* result = balanced(0, inOrder.size() -1, inOrder);

	return result;


}



//runs well check codetudio


int main() {




}