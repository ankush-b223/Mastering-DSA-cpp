#include<iostream>
#include<queue>
#include<stack>
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

	
	cout << "Enter data:- " << endl;
	int d;
	cin >> d;

	if (d == -1) {
		return NULL;
	}

	node* newNode = new node(d);

	root = newNode;
	

	cout << "Enter data to be inserted to the left of " << root->data << endl;
	root->left = buildTree(root->left);

	cout << "Enter data to be inserted to the right of " << root->data << endl;
	root->right = buildTree(root->right);



	return root;

}


void levelOrderTraversal(node* root) {

	if (root == NULL) {
		cout << "tree is empty" << endl;
	}

	queue<node*> q;
	q.push(root);


	q.push(NULL);


	while(!q.empty()) {

		node* front = q.front();
		q.pop();



		if (front == NULL) {
			cout << endl;

			if (!q.empty()) {
				q.push(NULL);
			}

		}
		else {
			cout << front->data << " ";

			if (front->left) {
				q.push(front->left);
			}
			if (front->right) {
				q.push(front->right);
			}

		}

	}




}

//1 stack right push left push for reverse stack logic
void preOrderS(node* root) {

	node* temp = root;

	stack<node*> s;
	s.push(root);

	while (!s.empty()) {

		temp = s.top();
		s.pop();

		cout << temp->data << " ";

		if (temp->right) {
			s.push(temp->right);
		}
		if (temp->left) {
			s.push(temp->left);
		}

	}
}


//1 stack
void inOrderS(node* root) {

	stack<node*> s;
	node* temp = root;

	while (!s.empty() || temp != NULL) {

		if (temp != NULL) {
			s.push(temp);
			temp = temp->left;
		}
		else {
			temp = s.top();
			s.pop();

			cout << temp->data;
			temp = temp->right;
		}

	}

}

//2 stacks
void postOrderS(node* root) {

	stack<node*> s;
	stack<node*> rightChild;
	node* temp = root;

	while (!s.empty() || temp != NULL) {

		if (temp != NULL) {

			if (temp->right) {
				rightChild.push(temp->right);
			}

			s.push(temp);
			temp = temp->left;
		}
		else {

			temp = s.top();

			if (!rightChild.empty() && temp->right == rightChild.top()) {
				temp = rightChild.top();
				rightChild.pop();
			}
			else {
				cout << temp->data << " ";
				s.pop();
				temp = NULL;
			}

		}

	}


}



int main() {


	node* root = NULL;

	root = buildTree(root);

	//levelOrderTraversal(root);
	
	postOrderS(root);

	

	return 0;
}