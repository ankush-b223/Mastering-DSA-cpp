#include<iostream>
#include<queue>
using namespace std;




class node {


public:

	int data;
	node* left;
	node* right;

	node(int value) {
		this->data = value;
		this->left = NULL;
		this->right = NULL;
	}

};


node* buildTree(node*& root) {

	int d; 
	cout << "Enter data" << endl;

	cin >> d;

	root = new node(d);

	if (root->data == -1) {
		return NULL;
	}



	cout << "Enter the left node of " << d << endl;
	root->left = buildTree(root->left);

	cout << "Enter the right node of " << d << endl;
	root->right = buildTree(root->right);


	return root;

}

void levelOrderTraversal(node*& root) {

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

//counts the no of nodes in a tree
int countNodes(node* root) {

	if (root == NULL) {
		return 0;
	}

	int answer = 1 + countNodes(root->left) + countNodes(root->right);

	return answer;

}


bool isCBT(node* root, int index, int nodes) {
	//base case
	if (root == NULL) {
		return true;
	}

	//if the index coming from call exceeds the total nodes in the given tree its not a CBT
	if (index >= nodes) {
		return false;
	}


	else {
		//call left 
		bool left = isCBT(root->left, 2 * index + 1, nodes);
		//call right
		bool right = isCBT(root->right, 2 * index + 2, nodes);

		//if both come true its a CBT
		if (left && right) {
			return true;
		}
		else {
			return false;
		}
	}
	
}


//checks the max order of a heap
bool isMaxOrder(node* root) {
	//if tree is null
	if (root == NULL) {
		return false;
	}
	//leaf node + base case (except underflow)
	if (!root->left && !root->right) {
		//leaf node is a max heap so return tree
		return true;
	}


	//the case of only right child exisiting is not possible in a CBT which is already verified

	//only left child
	if (root->right == NULL) {
		//check max heap condition i.e the root data is bigger than that of its child
		if (root->data > root->left->data) {
			return true;
		}
		else {
			return false;
		}
		//no recursive calls here as only left child exisiting are found only in the last level of a CBT
	}

	//both child
	else {

		//recursive calls to right and left
		bool left = isMaxOrder(root->left);
		bool right = isMaxOrder(root->right);

		//if the above subtree calls fetch true as maxHeap && the data of curr root's data is > than than of its childs then return true 

		if (root->data > root->left->data && root->data > root->right->data && left && right) {
			return true;
		}
		else {
			return false;
		}
	}
}


//ans driving fn 
bool isHeap(node*& root, int nodes) {

	//initiating index as 0
	int index = 0;
	//checks if the tree given is complete binary tree or not && is it of max heap order or not
	if (isCBT(root,index, nodes) && isMaxOrder(root)) {
		return true;
	}
	else {
		return false;
	}

}



int main() {


	node* root = NULL;

	root = buildTree(root);

	levelOrderTraversal(root);

	//this contains the total nodes in the tree given
	int totalNodes = countNodes(root);

	//fetches the ans
	bool ans = isHeap(root, totalNodes);


	return 0;
}