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

	cin >>d;

	while (d != -1) {
		root = insertBST(root, d);
		cin >> d;

	}

}


void makeInorder(node* root, vector<int>& inOrder) {

	if (root == NULL) {
		return;
	}

	makeInorder(root->left, inOrder);

	inOrder.push_back(root->data);

	makeInorder(root->right, inOrder);

}



bool twoSum(node* root, int target) {


	vector<int> inOrder;

	makeInorder(root, inOrder);

	int front = 0;
	int end = inOrder.size() - 1;

	int sum = 0;

	while (front < end) {

		sum = inOrder[front] + inOrder[end];

		if (sum == target) {
			return true;
		}

		else if (sum > target) {
			end--;
		}
		else {
			front++;
		}

	}

	return false;
}








int main() {


	node* root = NULL;

	takeInput(root);


	cout << endl;

	if (twoSum(root, 14)) {
		cout << "TRUEE!!" << endl;
	}
	else {
		cout << "FALSE!!" << endl;
	}



	return 0;
}




