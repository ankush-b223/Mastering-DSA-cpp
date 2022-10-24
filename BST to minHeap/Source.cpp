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


node* buildBST(node* root, int value) {

	if (root == NULL) {
		root = new node(value);

		return root;
	}

	if (value < root->data) {
		root->left = buildBST(root->left, value);
	}
	else {
		root->right = buildBST(root->right, value);
	}

	return root;

}

void takeInput(node* &root) {

	int d;

	cout << "Enter node data" << endl;
	cin >> d;

	while (d != -1) {
		root = buildBST(root, d);

		cin >> d;
	}

}



void levelOrderTraversal(node* root) {

	if (root == NULL) {
		return;
	}

	queue<node*> q;

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

	cout << endl;
}

//fn to get inOrder vector
void inorder(node* root, vector<int> &inOrder) {


	if (root == NULL) {
		return;
	}

	inorder(root->left , inOrder);

	inOrder.push_back(root->data);

	inorder(root->right,inOrder);

	
}

//NLR
//main fn
//the current index & inOrder vector is supplied along with the root
void toMinHeap(node* &root, vector<int> &inOrder, int &index) {
	//base case
	if (root == NULL) {
		return;
	}
	//NLR logic

	//N
	
	//change root->data to that of index of the inOrder vector
	root->data = inOrder[index++];

	//L

	//left recursive call
	toMinHeap(root->left, inOrder, index);

	//R

	//right recursive call
	toMinHeap(root->right, inOrder, index);
}


int main() {

	//creating the req BST
	node* root = NULL;

	takeInput(root);
	//printing the given BST
	levelOrderTraversal(root);

	//bst created

	//get the sorted inorder of the BST given & store it in a vector
	vector<int> inOrder;
	inorder(root, inOrder);

	//vector Inorder ready
	
	//start with index 0 

	//logic is for min heap root's data must be smaller than both of its child
	//++ acc to the question logic the left subtree of the min heap must me smaller than that of the right subtree

	//so the relation comes as root->data < leftChild->data < rightChild->data 
	//this is nothing but preOrder traversal NLR
	//so
	int index = 0;
	toMinHeap(root, inOrder, index);


	//print out the min heap created
	levelOrderTraversal(root);

	return 0;
}