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

		this ->left = NULL;
		this->right = NULL;

	}
};


node* insertBST(node* root,int d) {


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

	int d;
	cout << " Enter data " << endl;
	cin >> d;

	while (d != -1) {

		root = insertBST(root, d);
		cin >> d;
	}

}

//counter by ref to store its increments
int solve(node* root, int k, int& counter) {

	//base case
	if (root == NULL) {
		return -1;
	}

	//inorder LNR logic


	//left 

	int left = solve(root->left, k, counter);

	//answer condition fullfilled let answer passing as returns
	//this will only be true when answer is received and returned ( when counter == k )
	//else all conditions will return -1
	if(left != -1) {
		return left;
	}

	//node

	//increment counter
	counter++;

	//check for k
	if (counter == k) {
		return root->data;
	}

	//right
	return solve(root->right, k, counter);


}

//answer returner
int kthSmallestNode(node* root, int k) {

	int counter = 0;
	return solve(root, k, counter);


}




int main() {

	node* root = NULL;

	takeInput(root);

	cout<<kthSmallestNode(root, 3)<<endl;


	return 0;

}