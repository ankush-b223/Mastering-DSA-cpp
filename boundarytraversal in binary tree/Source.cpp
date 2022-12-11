#include <iostream>
#include <queue>
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
	int d;
	cin >> d;

	root = new node(d);

	if (root->data == -1) {
		return NULL;
	}

	cout << "Enter data to be inserted to the left of " << root->data << endl;

	root->left = buildTree(root->left);

	cout << "Enter data to be inserted to the right of " << root->data << endl;

	root->right = buildTree(root->right);


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

			if (temp->left) {
				q.push(root->left);
			}
			if (temp->right) {
				q.push(temp->right);
			}
		}
	}
	
}

//push leaf node data except leaf nodes
void goLeft(node* root , vector<int>& ans) {
	//base case
	if (root == NULL) {
		return;
	}
	//ignore leaf nodes
	if (root->left == NULL && root->right == NULL) {
		return;
	}

	//push data to ans
	ans.push_back(root->data);

	//if left exists , go left , ELSE!! go to right (with go left fn)
	if (root->left) {
		goLeft(root->left,ans);
	}
	//else!!
	else {
		goLeft(root->right,ans);
	}

}

//to push leaf nodes 
void goLeaf(node* root , vector<int>& ans) {

	//base case
	if (root == NULL) {
		return;
	}

	//if a leaf node >> push data to ans and return
	if (root->left == NULL && root->right == NULL) {
		
		ans.push_back(root->data);
		return;

	}
		
	//recursive call to both right and left sides 
		goLeaf(root->left,ans);
	
		goLeaf(root->right,ans);
	


}


//right nodes
void goRight(node* root, vector<int> &ans) {

	//base case
	if (root == NULL) {
		return;
	}
	//ignore leaf nodes as already pushed
	if (root->left == NULL && root->right == NULL) {
		return;
	}

	//if root->right exists go there ,ELSE! go to left
	if (root->right) {
		goRight(root->right,ans);
	}
	else {
		goRight(root->left,ans);
	}

	//push data here in reverse order as question demands
	ans.push_back(root->data);

}


//main driver function 
vector<int> boundaryTraversal(node* root) {

	//ans storing vector
	vector<int> ans;

	//base case
	//if null return the ans vector
	if (root == NULL) {
		return ans;
	}

	
	//push root data to ans ( 1st entry )
	ans.push_back(root->data);
	
	//left
	goLeft(root->left,ans);

	//leaf nodes // check with single root statement
	goLeaf(root->left,ans);
	goLeaf(root->right,ans);

	//right
	goRight(root->right,ans);

	return ans;

}



int main() {

	node* root = NULL;

	buildTree(root);

	//levelOrderTraversal(root);

	vector<int> result = boundaryTraversal(root);

	for (int count = 0; count < result.size(); ++count) {
		cout << result[count] << " ";
	}

	cout << endl;


	return 0;
}