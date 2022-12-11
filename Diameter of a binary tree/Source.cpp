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


node* buildTree(node* &root) {

	cout << "Enter data to be entered " << endl;
	int d;
	cin >> d;

	root = new node(d);

	if (root->data == -1) {
		return NULL;
	}

	cout << "Enter data to be inserted in the left of " << root->data << endl;
	root->left = buildTree(root->left);

	cout << "enter data to be entered in the right of " << root->data << endl;
	root->right = buildTree(root->right);


	return root;

}


int height(node* root) {

	if (root == NULL) {
		return 0;
	}

	int left = height(root->left);
	int right = height(root->right);


	int answer = max(left, right) + 1;

}

//optimised solution where height is calculated simultanouesly 
pair<int, int> diameterTree(node* root) {

	if (root == NULL) {
		pair<int, int> p = make_pair(0, 0);
		return p;
	}

	pair<int, int> left = diameterTree(root->left);
	pair<int, int> right = diameterTree(root->right);

	int opt1 = left.first;
	int opt2 = right.first;
	int opt3 = left.second + right.second + 1;

	pair<int, int> ans;
	ans.first = max(opt1, max(opt2, opt3) );
	ans.second = max(left.second, right.second) + 1;

	return ans;



}

//prints fastly calculated diameter, supporting returning fn
int printfastDiameter(node* root) {

	pair<int, int> ans = diameterTree(root);

	return ans.first;

}

//normal diameter fn bit slow 
int diameter(node* root) {


	if (root == NULL) {
		return 0;

	}


	int opt1 = diameter(root->left);
	int opt2 = diameter(root->right);
	int opt3 = height(root->left) + height(root->right)+1;

	int answer = max(opt1, max(opt2, opt3) );

	return answer;


}


int main() {

	node* root = NULL;

	buildTree(root);

	cout << printfastDiameter(root) << endl;


	return 0;
}