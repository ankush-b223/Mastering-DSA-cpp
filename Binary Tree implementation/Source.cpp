#include <iostream>
#include <queue>
using namespace std;


class node {

public:

	int data;
	node* left;
	node* right;


	node(int value) {
		this->data = value;
		this->left = NULL;
		this->right = NULL;
	}

};

//fn def
//please call by reference
node* createTree(node* &root) {

	//take data
	int data;
	cout << "Enter data "<< endl;
	cin >> data;

	//make new node as came in as argument
	root = new node(data);

	//base case (to return)
	if (data == -1) {
		return NULL;
	}

	//take the left childs first
	cout << "Enter data to be inserted in left of " << data << endl;
	root->left = createTree(root->left);

	//then move to right childs
	cout << "Enter data to be inserted in right of " << data << endl;
	root->right = createTree(root->right);

	//kinda traversal like inorder LNR kindaaaa!!
	
	//return 
	return root;

}


void createTreeLOT(node*& root) {

	queue<node*> q;

	cout << "enter data for root" << endl;
	int data;
	cin >> data;

	root = new node(data);

	q.push(root);

	while (!q.empty()) {

		node* temp = q.front();
		q.pop();

		cout << "enter data for left of " << temp->data << endl;
		int lData;
		cin >> lData;
		

		if (lData != -1) {
			temp->left = new node(lData);
			q.push(temp->left);

		}

		cout << "enter data for right of " << temp->data << endl;
		int rData;
		cin >> rData;

		

		if (rData != -1) {
			temp->right = new node(rData);
			q.push(temp->right);
		}

	}




}


//l->left
//r->right
//n->node basically print node's data

void inOrder(node* root) {
	//lnr

	//base case
	if (root == NULL) {
		return;
	}


	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);

}





void preOrder(node * root) {
	//nlr
	
	//base case
	if (root == NULL) {
		return;
	}


	cout << root->data << " ";
	inOrder(root->left);
	inOrder(root->right);


}




void postOrder(node *root) {
	//lrn

	//base case
	if (root == NULL) {
		return;
	}

	inOrder(root->left);
	inOrder(root->right);
	cout << root->data << " ";

}



void levelOrderTraversal(node* &root) {

	//make q contqaing node type elements like root , root->left , root->right etc etc
	queue<node*> q;

	//push the root as first element
	q.push(root);
	//separator concept 
	//this marks the end of a level and endl needs to be executed 
	q.push(NULL);

	//traverse queue
	while (!q.empty()) {

		//traversing node temp pointed towards front
		node* temp = q.front();
		//front is removed from queue
		q.pop();

		
		//if temp is null give new line
		if (temp == NULL) {
			
			cout << endl;
			
			//if queue is empty return 
			//if not empty push null to indicate next level completion
			if (!q.empty()) {
				
				q.push(NULL);
				
			}
		}
		else {

			//print temp data 
			cout << temp->data << " ";

			//if there is temp's left , then  push to queue
			if (temp->left) {
				q.push(temp->left);
			}

			//if there is a temp's right , then push to queue
			if (temp->right) {
				q.push(temp->right);
			}
		}
	}

}


int main() {


	node* root = NULL;

	createTreeLOT(root);

	cout << endl;

	levelOrderTraversal(root);

	/* createTree(root);

	cout << endl;

	//cout << "Printing tree data using level order traversal" << endl;

	//levelOrderTraversal(root);

	inOrder(root);
	cout << endl;
	preOrder(root);
	cout << endl;
	postOrder(root);
	cout << endl;

	*/


	return 0;
}