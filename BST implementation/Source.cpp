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
		this->right = NULL;
		this->left = NULL;

	}

};

void Leveltraversal(node* root) {

	queue<node*> q;

	if (root == NULL) {
		cout << "Empty tree" << endl;
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

			if (temp->left !=NULL) {
				q.push(temp->left);
			}
			if (temp->right !=NULL ) {
				q.push(temp->right);
			}
		}


	}

}











node* insertBST(node* root, int value) {

	//base case 
	//adds new node
	if (root == NULL) {
		//making new node
		root = new node(value);

		return root;
	}

	//go to left sub tree
	if (root->data > value) {
		root->left = insertBST(root->left, value);
	}
	//go to right subtree
	else {
		root->right = insertBST(root->right, value);
	}

	//very imp
	return root;
}



void takeInput(node* &root) {

	int d;
	//taking first input
	cin >> d;

	// processes till -1
	while (d != -1) {
		//call insertion
		root = insertBST(root, d);
		//take next input
		cin >> d;
	}

}


//searching iteratively 
node* searchIBST(node* root, int key) {

	queue<node*> q;
	//flag def initially false
	bool flag = 0;

	//push root to queue
	q.push(root);

	//lot logic
	while (!q.empty()) {

		//fetch front element
		node* temp = q.front();
		//pop it
		q.pop();

		//if key found
		if (temp->data == key) {
			//make flag true
			flag = 1;
			//return
			return temp;

		}

		//check left
		if (temp->left) {
			q.push(temp->left);
		}
		//check right
		if (temp->right) {
			q.push(temp->right);
		}

	}

	//if key isnt found
	if (flag == 0) {
		cout << "KEY doesnt exist" << endl;
		return NULL;
	}


}








//searching recursively
node* searchBST(node* root, int key) {

	//base case
	if (root == NULL) {
		return NULL;
	}
	//if root with key data is found
	if (root->data == key) {
		//return it
		return root;
	}


	//if root data is bigger than key >> go left
	if (root->data > key) {
		root = searchBST(root->left,key);
	}
	//go right
	else {
		root = searchBST(root->right, key);
	}

	//return 
	return root;

}



node* minBST(node* root) {

	//edge case tree empty
	if (root == NULL) {
		return NULL;
	}

	//if lefmost node is reached return that coz that is min in BST
	if (root->left == NULL) {
		return root;
	}
	//else recursively move to the left of root
	else {
		root = minBST(root->left);
	}

	//return root
	return root;

}


node* maxBST(node* root) {
	
	//edge case
	if (root == NULL) {
		return NULL;
	}

	//right most node in tree reached >> max node in tree so return it
	if (root->right == NULL) {
		return root;
	}
	//else recursively move to the right of root
	else {

		root = maxBST(root->right);
	}

	//return root
	return root;

}




//very imp ********
//fn to delete node

node* deleteNodeBST(node* root, int key) {

	//edge case
	if (root == NULL) {

		return NULL;
	}

	//if node to be deleted is found
	if (root->data == key) {

		//3 cases>>>>>>>>>>>>>>>>>>>>

		//0 child 

		//leaf node
		if (root->left == NULL && root->right == NULL) {
			//deleted node and return null
			delete root;
			return NULL;

		}


		//1 child
		 
			//left child exists
		if (root->left != NULL && root->right == NULL) {
			//store left child data in temp
			node* temp = root->left;
			//delete node
			delete root;

			//return stored temp
			return temp;
		}


			//right child exists
		if (root->right != NULL && root->left == NULL) {
			//same as left
			node* temp = root->right;
			delete root;

			return temp;
		
		}

		//2 child
		//if both childs exist
		if(root->left != NULL && root->right != NULL) {

			//fetch for the min element in right subtree from root and store its data
			int replace = minBST(root->right)->data;
			
			//replace min data found, with root's data
			root->data = replace;

			//call recursively to delete the node containing the replace data ( minimum value )
			//check new value is replace
			//this call goes to delete the min of right subtree
			root->right = deleteNodeBST(root->right, replace);

			return root;


		}


	}

	//if node not yet found move left and right
	if (root->data > key) {
		root->left = deleteNodeBST(root->left, key);

	}
	else {
		root->right = deleteNodeBST(root->right, key);
	}

	return root;
}













//driver code
int main() {

	//root node creation
	node* root = NULL;

	//taking BST TREE & creating it
	cout << "Enter BST elements " << endl;
	takeInput(root);

	
	//printing made BST
	Leveltraversal(root);




	cout << endl;

	/* 
	//checking recursive search fn
	node* result = searchBST(root, 5);
	cout << result->data << endl;

	*/


	//min max fn checks


	/*
	node* min = minBST(root);
	cout << min->data << endl;

	node* max = maxBST(root);

	cout << max->data << endl;

	*/


	root = deleteNodeBST(root, 50);

	cout << endl;

	Leveltraversal(root);



	return 0;
}