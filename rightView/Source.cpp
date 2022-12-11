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

	//base case
	if (root == NULL) {
		return;
	}

	//if data is already inserted in that particular level then ignore else push curr data
	//if level is same as vector size then no data entered so push
	if (level == ans.size()) {
		ans.push_back(root->data);
	}

	//recursive calls first to right as its for right view 
	solve(root->right, ans, level + 1);
	solve(root->left, ans, level + 1);

}

//returning fn
vector<int> rightView(node* root) {

	vector<int> ans;
	
	//initiaqlize level as 0 
	solve(root, ans, 0);

	return ans;


}

int main() {

	node* root = NULL;

	buildTree(root);

	vector<int> result = rightView(root);

	for (auto i : result) {

		cout << i << " ";
	}
	cout << endl;


	return 0;
}