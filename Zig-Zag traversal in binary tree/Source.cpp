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

node* buildTree(node*& root) {

	cout << "Enter data " << endl;
	int data;
	cin >> data;

	root = new node(data);

	if (root->data == -1) {
		return NULL;
	}

	cout << "Enter data to be inserted in the left of " << root->data << endl;
	root->left = buildTree(root->left);

	cout << "Enter data to be inserted in the right of " << root->data << endl;
	root->right = buildTree(root->right);

	return root;

}



vector<int> zigZagTraversal(node* root) {

	queue<node*> q;
	vector<int> ans;

	if (root == NULL) {
		cout << "Tree is empty" << endl;
	}

	q.push(root);
	bool flagLR = true;
	
	while (!q.empty()) {
		
		int size = q.size();
		//imp
		vector<int> tempo(size);

		

		for (int count = 0; count < size; ++count) {

			node* temp = q.front();
			q.pop();
			int index;

			if (flagLR) {
				index = count;
			}
			else {
				index = size - count - 1;
			}

			tempo[index] = temp->data;

			if (temp->left != NULL) {
				q.push(temp-> left);
			}
			if (temp->right != NULL) {
				q.push(temp->right);
			}

		}

		flagLR = !flagLR;

		for (int i = 0; i < tempo.size(); ++i) {
			ans.push_back(tempo[i]);
		}

	}

	return ans;

}



int main() {

	node* root = NULL;

	buildTree(root);

	vector<int> result = zigZagTraversal(root);

	for (auto i : result) {
		cout << i << " ";
	}
	cout << endl;


	return 0;
}