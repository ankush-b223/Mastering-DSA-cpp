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

void levelOrderTraversal(node*& root) {

	queue<node*> q;

	if (root == NULL) {
		cout << "tree is empty" << endl;
		return;
	}

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


//fn def
pair<bool,int> isSumTree(node* root) {

	//base cases
	if (root == NULL) {
		pair<bool, int> base = make_pair(true, 0);
		return base;
	}

	//leaf node case , see leaf node returns >> its data as sum ( .second )
	if (root->left == NULL && root->right == NULL) {
		pair<bool, int> base2 = make_pair(true, root->data);
		return base2;
	}

	//recursive calls left and right
	pair<bool, int> left = isSumTree(root->left);
	pair<bool, int> right = isSumTree(root->right);

	//check bools of left subsystem & right subsystem
	bool leftAns = left.first;
	bool rightAns = right.first;

	//sum check 
	bool sumCheck = left.second + right.second == root->data;

	//returning variable def
	pair<bool, int> ans;

	//entire left/right subsytem's sum should be same  >> root data is also added 
	ans.second = left.second + right.second + root->data;

	//if all condn true >> return true  ,, else false
	if (leftAns && rightAns && sumCheck) {
		ans.first = true;
	}
	else {
		ans.first = false;
	}

	return ans;
}


//bool return fn def
bool isSumreturn(node* root) {
	return isSumTree(root).first;
}








int main() {

	node* root = NULL;

	buildTree(root);
	cout << endl;

	levelOrderTraversal(root);

	if (isSumreturn(root)) {
		cout << "Is Sum Tree" << endl;
	}
	else {
		cout << "Not sum tree" << endl;
	}


	return 0;
}