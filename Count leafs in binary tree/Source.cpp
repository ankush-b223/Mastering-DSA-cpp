#include<iostream>
#include <queue>
using namespace std;

class node {

public:

	int data;
	node* right;
	node* left;


	node(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}


};


node* createTree(node*& root) {

	cout << "Enter data " << endl;
	int data;

	cin >> data;

	root = new node(data);

	if (data == -1) {
		return NULL;
	}

	cout << "Enter value to be inserted to left of " << root->data << endl;
	root->left = createTree(root->left);

	cout << "Enter value to be inserted to right of " << root->data << endl;
	root->right = createTree(root->right);

	return root;
	

}


void levelOrderTraversal(node* root) {

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

			if (temp->left != NULL) {
				q.push(temp->left);
			}

			if (temp->right != NULL) {
				q.push(temp->right);
			}

		}

	}



}

//calling by reference count so as the value is stored to solve function call return
void countinorder(node* root , int &count) {
	//lnr

	if (root == NULL) {
		return;
	}
	countinorder(root->left,count);

	if (root->left == NULL && root->right == NULL) {
		count++;
	}

	countinorder(root->right,count);


}

//to return answer integer fn
int solve(node* root) {

	//initialize
	int count = 0;

	countinorder(root, count);

	return count;


}

int main() {

	node* root = NULL;


	createTree(root);

	//levelOrderTraversal(root);
	

	int answer = solve(root);

	cout << answer << endl;
	

	return 0;
}