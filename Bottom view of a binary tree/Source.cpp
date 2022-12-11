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


vector<int> bottomView(node* root) {

	vector<int> ans;

	map<int, int> nodeMap;

	queue<pair<node*, int> > q;

	if (root == NULL) {
		return ans;
	}

	//overwrites and stores the last elelment in the view
	q.push(make_pair(root, 0));

	while (!q.empty()) {

		pair<node*, int> temp = q.front();
		q.pop();

		node* frontNode = temp.first;
		int horDist = temp.second;

		nodeMap[horDist] = frontNode->data;

		if (frontNode->left) {
			q.push(make_pair(frontNode->left, horDist - 1));
		}

		if (frontNode->right) {
			q.push(make_pair(frontNode->right, horDist + 1));
		}

	}

	for (auto i : nodeMap) {
		ans.push_back(i.second);
	}

	return ans;

}






int main() {


	node* root = NULL;

	buildTree(root);

	leveltraversal(root);

	cout << endl;

	vector<int> result = bottomView(root);

	for (auto i : result) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}