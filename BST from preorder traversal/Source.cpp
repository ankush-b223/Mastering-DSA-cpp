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


node* solve(vector<int> preOrder, int min, int max, int &count) {

	//if index goes out of bound>> array traversing is done
	if (count >= preOrder.size()) {
		return NULL;
	}

	//if element is out of bound of range
	if (preOrder[count] < min || preOrder[count] > max) {
		return NULL;
	}

	//make new node i.e root and put count index data in it
	node* root = new node(preOrder[count++]);

	//call for left - right recursively
	
	//for left the range is min -> root->data
	root->left = solve(preOrder, min, root->data, count);

	//for right range is root->data >>> max 
	root->right = solve(preOrder, root->data, max, count);

	//returning the root of BST created
	return root;

}


node* preToBST(vector<int> preOrder) {

	//make infinity ranges
	int min = INT_MIN;
	int max = INT_MAX;

	//index tracker
	int count = 0;

	//pass to fn and return root of created BST
	return solve(preOrder, min,max, count);


}











int main() {
	


	return 0;
}