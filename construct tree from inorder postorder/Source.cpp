#include<iostream>
#include<queue>
#include<map>
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


node* buildTree(node*& root) {

	cout << "Enter data" << endl;
	int d;
	cin >> d;

	root = new node(d);

	if (root->data == -1) {
		return NULL;
	}


	cout << "enter element to be inserted in the left of " << root->data << endl;
	root->left = buildTree(root->left);

	cout << "enter element to be inserted in the right of " << root->data << endl;
	root->right = buildTree(root->right);


	return root;


}

void leveltraversal(node* root) {

	queue<node*>q;

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

}


void preOrder(node* root) {

	if (root == NULL) {
		return ;

	}

	cout << root->data << " ";

	preOrder(root->left);
	preOrder(root->right);

}





void createMap(int in[], map<int, int>& nodeToIndex, int size) {

	for (int count = 0; count < size; ++count) {
		nodeToIndex[in[count]] = count;
	}

}

node* solve(int in[], int post[], int& postIndex, int inStart, int inEnd, int size, map<int, int> &nodeToIndex) {


	if (postIndex<0 || inStart>inEnd) {
		return NULL;
	}


	int element = post[postIndex--];

	node* root = new node(element);

	int position = nodeToIndex[element];

	root->right = solve(in, post, postIndex, position + 1, inEnd, size,nodeToIndex);

	root->left = solve(in, post, postIndex, inStart, position - 1, size, nodeToIndex);

	return root;

}

node* buildIn_Post(int in[], int post[], int size) {

	int postIndex = size - 1;

	map<int, int> nodeToIndex;
	createMap(in, nodeToIndex, size);

	node* ans = solve(in, post, postIndex, 0, size - 1, size, nodeToIndex);


	return ans;
}




int main() {

	int in[8] = { 4 ,8, 2, 5, 1, 6, 3, 7 };
	int post[8] = { 8, 4, 5, 2, 6, 7, 3, 1 };

	int size =8 ;
	
	node* root = buildIn_Post(in, post, size);

	preOrder(root);

	return 0;
}