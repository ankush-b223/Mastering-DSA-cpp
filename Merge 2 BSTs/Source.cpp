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










//making inorder vector fn
void makeInorder(node* root, vector<int> &inOrder) {

	if (root == NULL) {
		return;
	}

	makeInorder(root->left, inOrder);

	inOrder.push_back(root->data);

	makeInorder(root->right, inOrder);


}


//merging two sorted vectors to 1 merged sorted vector
vector<int> merge2array(vector<int> &inOrder1, vector<int> &inOrder2) {

	vector<int> merged(inOrder1.size()+ inOrder2.size());
	

	int i = 0;
	int j = 0;

	int k = 0;

	int size1 = inOrder1.size();
	int size2 = inOrder2.size();


	while (i < size1 && j < size2) {


		if (inOrder1[i] < inOrder2[j]) {

			merged[k] = inOrder1[i];
			k++;
			i++;

		}
		else {

			merged[k] = inOrder2[j];
			k++;
			j++;

		}
	}
	

	while (i < inOrder1.size()) {

		merged [k++] = inOrder1[i++];

	}

	while (j < inOrder2.size()) {

		merged[k++] = inOrder2[j++];

	}


	return merged;

}



//creating tree from one sorted array of inorder
node* array2BST(vector<int> mergedArray , int start , int end ) {


	if (start > end) {
		return NULL;
	}

	int mid = (start + end) / 2;

	node* newRoot = new node(mergedArray[mid]);

	newRoot->left = array2BST(mergedArray, start, mid - 1);
	newRoot->right = array2BST(mergedArray, mid + 1, end);
	
	


	return newRoot;

}


//main answer returning fn
node* merge2BST(node* root1, node* root2) {

	//creating two inorder storing vectors
	vector<int> inOrder1;
	vector<int> inOrder2;

	//making the inorders
	makeInorder(root1, inOrder1);
	makeInorder(root2, inOrder2);


	//merging the 2 inorder vectors
	vector<int> merged = merge2array(inOrder1, inOrder2);

	
	//for vector to BST args
	int start = 0;
	int end = merged.size()-1;

	
	//this will give the root node of merged tree
	node* result = array2BST(merged,start,end);

	return result;


}




int main() {

	node* root1 = NULL;
	node* root2 = NULL;

	takeInput(root1);

	cout << endl;


	takeInput(root2);

	node* result = merge2BST(root1, root2);

	cout << result->data << endl;


	return 0;

}