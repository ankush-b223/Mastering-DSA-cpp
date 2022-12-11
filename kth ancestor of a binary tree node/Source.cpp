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

//calling k by ref to retain values
node* solve(node* root, int n1, int& k) {

	//base case
	if (root == NULL) {
		return NULL;
	}

	//if root call is required node
	if (root->data == n1) {
		//return root
		return root;
	}

	//recursive calls to left & right
	node* leftAns = solve(root->left, n1, k);
	node* rightAns = solve(root->right, n1, k);


	//if left side gives non null 
	//you reach an ancestor so reduce k
	if (leftAns != NULL && rightAns == NULL) {
		//reducing k
		k--;

		//check if k <=0 , if k =0  >> we have reached required ancestor
		if (k <= 0) {
			//to lock answer
			//setting k to max value so it cant never be 0 further and this particular node 
			//keeps getting returned to upcoming calls
			k = INT_MAX;
			//locking & returning req node
			return root;

		}

		//if k not 0  then return current non null node
		return leftAns;


	}

	//same logic for right
	if (rightAns != NULL && leftAns == NULL) {

		k--;
		if (k <= 0) {
			k = INT_MAX;
			return root;
		}

	}

	//if both sides return null >> return  null
	return NULL;

}

//return driving fn 
int kthAncestor(node* root, int n1 , int k) {

	node* ans = solve(root, n1, k);

	//if node required not found OR 
	//root node is node of which ancestor is to  be found ( expecting k != 0  in any case )
	if (ans->data == NULL || ans->data == n1) {
		return -1;
	}

	return ans->data;
}




int main() {

	node* root = NULL;

	buildTree(root);

	cout << kthAncestor(root,4 ,2 ) << endl;

	return 0;
}