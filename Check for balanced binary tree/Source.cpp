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

void levelOrderTraversal(node* &root) {

	queue<node*> q;

	if (root == NULL) {
		cout << "tree is empty"<<endl;
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

//height fn def
int height(node* &root) {

	if (root == NULL) {
		return 0;
	}

	int left = height(root->left);
	int right = height(root->right);

	int ans = max(left, right) + 1;

	return ans;

}
/* 
//fn def
bool isBalanced(node* &root) {

	//base case
	if (root == NULL) {
		return true;
	}

	//recursive calls
	bool left = isBalanced(root->left);
	bool right = isBalanced(root->right);

	//checks condition ( height diff less than equal to 1 )
	bool diff = abs ( height(root->left) - height(root->right) ) <= 1;

	//if all conditions true return true
	if (left && right && diff) {
		return true;
	}
	//else not balanced
	else {
		return false;
	}


}
*/ 


//the pair would contain the bool whether and the height also
pair<bool, int> isBalancedFast(node* root) {

	//base case
	if (root == NULL) {

		//base case from null nodes height is 0
		pair<bool, int> base = make_pair(true, 0);
		return base;
	}



	//recursive calls
	pair<bool, int> left = isBalancedFast(root->left);
	pair<bool, int> right = isBalancedFast(root->right);

	//selecting bool returns of left and right subtree
	bool leftAns = left.first;
	bool rightAns = right.first;



	//checks condition ( height diff less than equal to 1 )
	bool diff = abs ( left.second - right.second ) <= 1;

	
	//returning variable
	pair<bool, int> ans;

	//update height
	ans.second = max(left.second, right.second) + 1;



	//if all conditions true return true
	if (leftAns && rightAns && diff) {
		ans.first = true;
	}
	//else not balanced
	else {
		ans.first = false;
	}

	return ans;

}

//driver returning fn
bool isBalancedReturn(node* root) {

	return isBalancedFast(root).first;
}




//driver code
int main() {

	node* root = NULL;

	buildTree(root);

	//prints tree defined
	levelOrderTraversal(root);
	cout << endl;


	/* 
	if (isBalanced(root)) {
		cout << "Balanced" << endl;
	}
	else if(!isBalanced(root)) {
		cout << "Not Balanced" << endl;
	}

	*/

	if (isBalancedReturn(root)== true) {
		cout << "Balanced" << endl;
	}
	else if (isBalancedReturn(root) == false) {
		cout << "Not Balanced" << endl;
	}


	return 0;
}