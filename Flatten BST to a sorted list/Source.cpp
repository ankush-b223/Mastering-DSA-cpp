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

//makes sorted inorder vector carrying the nodes
void makeInorder(node* root, vector<node*> &inOrder) {

	if (root == NULL) {
		return;
	}

	makeInorder(root->left,inOrder);

	inOrder.push_back(root);

	makeInorder(root->right, inOrder);


}




node* flattenBST(node* root) {

	//create vector to store inorder nodes
	vector<node*> inOrder;
	
	//get the vector
	makeInorder(root, inOrder);

	

	int size = inOrder.size();

	//the 2nd pointer which tracks the right of current node
	//starts from 1 coz it tracks the right element
	int next = 1;

	//create node to be returned with data of first node in inOrder vector
	node* newRoot = inOrder[0];

	//make temp current node tracker to traverse
	node* curr = newRoot;


	
	//run loop till second last node
	for (int count = 0; count < size -1; ++count) {

		//here the to be right node is named temp
		//next pointer is post incremented
		node* temp = inOrder[next++];

		//makes left of current node null and attaches curr -> right to temp created just above
		curr->left = NULL;
		curr->right = temp;


		//move curr to next node i.e temp
		curr = temp;


	}

	//case of last node

	//make both null
	curr->left = NULL;
	curr->right = NULL;

	//return newRoot 
	return newRoot;



}





// making tree with new node creation
/* 

void makeInorder(TreeNode<int>* root, vector<int> &inOrder) {

	if (root == NULL) {
		return;
	}

	makeInorder(root->left,inOrder);

	inOrder.push_back(root->data);

	makeInorder(root->right, inOrder);
}




TreeNode<int>* flatten(TreeNode<int>* root)
{
	// Write your code here

	vector<int> inOrder;

	makeInorder(root, inOrder);

	int size = inOrder.size();

	int next = 1;

	TreeNode<int>* newRoot = new TreeNode<int>(inOrder[0]);

	//TreeNode<int>* curr = root;

	TreeNode<int>* curr = newRoot;

	for (int count = 0; count < size -1; ++count) {

		TreeNode<int>* temp = new TreeNode<int>(inOrder[next++]);

		curr->left = NULL;
		curr->right = temp;

		curr = temp;

	}

	curr->left = NULL;
	curr->right = NULL;


	return newRoot;





}





*/






int main() {

	node* root = NULL;

	takeInput(root);

	node* newroot = flattenBST(root);

	//cout << newroot->data << endl;


	return 0;
}