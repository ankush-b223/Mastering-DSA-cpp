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



void takeinput(node* &root) {
	
	cout << "Enter data " << endl;
	int d;

	cin >> d;

	while (d != -1) {
		root = insertBST(root, d);
		cin >> d;
	}


}



pair<int, int> predSucc(node* root, int key) {

	//initialize traversing node object temp & req ans variables
	node* temp = root;
	int succ=-1;
	int pred=-1;

	//run loop till temp gets to key node & is also not null
	//not null condition to handle case where key node doesnt exist in tree0
	while (temp->data != key && temp!=NULL) {

		//if temp data > -> go left
		if (temp->data > key) {
			//store maybe successor node's data
			succ = temp->data;
			//go left
			temp = temp->left;

		}

		else {
			//store maybe predecessor node's data
			pred = temp->data;
			//go right
			temp = temp->right;
		}

	}

	//succ & pred is stored in loop to handle case where key node is a leaf node & its left right are null
	//in such a case succ & pred wont be stored att all if not in the previous loop already stored

	//here temp is key node;

	//go to left subtree
	node* left = temp->left;

	//search for the max element in left subtree i.e our predecessor 
	//so in subtree move to the right most element in the left subtree

	//till left not null
	while (left != NULL) {

		//store predecessor
		pred = left->data;
		//move right for rightmost (maximum) element
		left = left->right; 

	}

	//here pred has predecessor node data

	//same logic for right subtree for succesoor
	node* right = temp->right;

	//here we look for the min most element in rioht subtree which will be the successor
	//to find min we go left left in right subtree

	while (right != NULL) {
		succ = right->data;
		right = right->left;

	}

	//here we have succ data

	//make pair return ans
	pair<int, int> ans = make_pair(pred,succ);

	return ans;


}
















int main() {

	node* root = NULL;

	takeinput(root);

	cout << endl;

	pair<int, int> ans = predSucc(root, 10);
	cout << ans.first << " " << ans.second << endl;



	return 0;
}