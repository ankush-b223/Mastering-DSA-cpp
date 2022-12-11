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

//call count by ref to retain values
void solve(node* root, int k, vector<int> path,int &count) {

	//base case
	if (root == NULL) {
		return;

	}

	//pushh curr node data to vector
	path.push_back(root->data);

	//recursive calls
	solve(root->left, k, path, count);
	solve(root->right, k, path, count);

	//initialize sum
	int sum = 0;
	//run loop through vector to check if any combination sum gives k
	for (int i = path.size() - 1; i >= 0; i--) {
		sum += path[i];

		//got k so increase count
		if (sum == k) {
			++count;
		}
	}
	
	//on way back pop last element
	path.pop_back();

}

//returning fn
int kpaths(node* root, int k) {

	//vector where corresponding root node data will be stored
	vector<int> path;
	int count = 0;

	solve(root, k, path, count);

	return count;


}




int main() {


	node* root = NULL;

	buildTree(root);

	cout << endl;

	int ans = kpaths(root, 3);

	cout << ans << endl;		


	return 0;
}
