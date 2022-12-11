#include<iostream>
#include <queue>
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


//two nodes n1 n2 whose LCA is to be returned
node* LCA(node* root, node* n1, node* n2) {

	//base case / edge case
	if (root == NULL) {
		return NULL;
	}


	//fetching data members all all objects
	int rootData = root->data;
	int n1Data = n1->data;
	int n2Data = n2->data;

	//if root data is bigger than both n1 & n2>>>>  ->go left 
	if (rootData > n1Data && rootData > n2Data) {
		//going left
		return LCA(root->left, n1, n2);
	}
	//if root data is smaller than both n1 & n2 then go right
	else if (rootData < n1Data && rootData < n2Data) {
		//going right
		return LCA(root->right, n1, n2);
	}
	//if( root data is bigger than n1 & smaller than n2  or vice versa >>>> its
	//condition for ancestor node that too LCA
	else {
		//so return this root as its LCA of n1 & n2

		//returing ans
		return root;
	}


}






//driver code
int main() {

	node* root = NULL;

	takeInput(root);

	node* n1 = new node(3);
	node* n2 = new node(5);

	node* result = LCA(root, n1, n2);

	cout << endl;

	cout << result->data << endl;




	return 0;
}