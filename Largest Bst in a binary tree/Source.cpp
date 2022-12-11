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











//to send data during calls 
//we need to send four data members
//so we create a class info
//they will have following data meembers


class info {

public:

	int min;//to store minimum node data in subtree
	int max;//max node data
	bool isBST;//whether BST of not
	int size;//size of BST

};



//main fn def
info solve(node* root, int &maxSize) {
	
	//base case 
	if (root == NULL) {
		//min is INT_max so in next call it gets msutly replaced by root data
		//max is INT_MIn same logic
		//size is 0 since its NULL
		return{ INT_MAX,INT_MIN,true,0 };
	}

	//calling & storing left and right data members
	info left = solve(root->left, maxSize);
	info right = solve(root->right, maxSize);

	//for current node info this object
	info currNode;

	//curr size is size from left right calls plus itself which is why >>( +1 )
	currNode.size = left.size + right.size + 1;
	//min b/w root data & left subtree minimum element
	currNode.min = min(root->data, left.min);
	//max b/w root data & right subtree max
	currNode.max = max(root->data, right.max);

	//if left right both BSTs
	if (left.isBST && right.isBST) {
		//if the current root data is bigger than left's max element 
		//&&
		//the curr root data is smaller than right's min element

		//its bst else all case false
		if (root->data > left.max && root->data < right.min) {
			currNode.isBST = true;
		}
		else {
			currNode.isBST = false;
		}

	}
	else {
		currNode.isBST = false;
	}

	//if isBST then update maxSize
	if (currNode.isBST) {
		//max of curr size & maxSize
		maxSize = max(currNode.size, maxSize);
	}

	//return currNoDe
	return currNode;

}


//answer returning fn 
int largestBST(node* root) {

	//answer variable
	int maxSize = 0;

	//fn call
	info temp = solve(root, maxSize);

	//return maxSize which has correct value since passed by ref in solve fn
	return maxSize;

}


















