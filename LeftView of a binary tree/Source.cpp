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

void solve(node* root, vector<int>& ans, int level) {

	if (root == NULL) {
		return;
	}
	//check right view file for explanation
	if (level == ans.size()) {
		ans.push_back(root->data);
	}

	//left call first since left view 
	solve(root->left, ans, level + 1);
	solve(root->right, ans, level + 1);


}

vector<int> leftView(node* root) {

	vector<int> ans;

	solve(root, ans, 0);

	return ans;

}




int main() {
	node* root = NULL;

	buildTree(root);

	vector<int> result = leftView(root);

	for (auto i : result) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}