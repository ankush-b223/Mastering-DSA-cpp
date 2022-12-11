#include <iostream>
#include<vector>
using namespace std;


class node {

public:

	int data;
	node* left = NULL;
	node* right = NULL;


	node(int d) {
		this->data = d;
		this->left = NULL;
		this->right = NULL;

	}

};


node* insertBST(node* root, int d) {

	if (root == NULL) {
		root = new node(d);

		return root;
	}

	if (root->data > d) {
		root->left = insertBST(root->left, d);
	}
	else {
		root->right = insertBST(root->right, d);
	}

	return root;
}



void takeInput(node*& root) {

	cout << "Enter data " << endl;

	int d;

	cin >> d;

	while (d != -1) {
		root = insertBST(root, d);
		cin >> d;

	}

}










//fn to convert BST to Doubly Linked List
void convertToDLL(node* root , node* &head) {

	//base case
	if (root == NULL) {
		return;
	}

	//we use right pointer as next
	//left as prev pointer 

	//recursive call to right subtree of root
	convertToDLL(root->right,head);
	//the head coming from the above call
	//is attached to right of root

	root->right = head;

	//the head that came from call >> its keft is linked to root ( doubly logic )
	if (head != NULL) {
		head->left = root;
	}

	//update head
	head = root;

	//call to do same with left subtree
	convertToDLL(root->left, head);


	//by ref calll
	//so head will contain DLL from root BST given as argument
}



//function to merge two linked lists sorted!
node* mergeLL(node* head1, node* head2) {

	//creating new mergedLL head and tail
	node* head = NULL;
	node* tail = NULL;

	//merge two arrays logic 
	//head1 pointer for LL1 & head2 for LL2
	while (head1 != NULL && head2 != NULL) {
		//if head1 data is smaller than head2 data
		if (head1->data < head2->data) {
			//insert head1 data first into mergeLL
			//case of first insertion where head is NULL
			if (head == NULL) {
				//put element
				//assign head & tail to it
				head = head1;
				tail = head;

				//doubly so left points prev i.e NULL for head
				head->left = NULL;

				//update head1 pointer to next node in LL1
				head1 = head1->right;
			}
			else {

				//normal flow
				
				//insertion at tail taking place
				tail->right = head1;
				//doubly logic so head2 left points towards curr tail
				head1->left = tail;

				//tail updated
				tail = head1;

				//head1 updated
				head1 = head1->right;
			}

		}

		else {
			//same logic for head2 data as smaller element
			if (head==NULL) {
				head = head2;
				tail = head;

				head->left = NULL;

				head2 = head2->right;
			}
			else {

				
				tail->right = head2;
				head2->left = tail;

				tail = head2;

				head2 = head2->right;

			}

		}

	}

	//checking for left over nodes in both Linked lists
	//for LL1
	while (head1 != NULL) {
		
		tail->right = head1;
		head1->left = tail;

		tail = head1;

		head1 = head1->right;
	}
	//for LL2
	while (head2 != NULL) {
		
		tail->right = head2;
		head2->left = tail;

		tail = head2;

		head2 = head2->right;

	}

	//return head i.e head of merged sorted LL
	return head;

}

//fn to count number of nodes in a LL
int nodeCounter(node* head) {
	node* temp = head;

	int count = 0;

	while (temp != NULL) {
		count++;

		temp = temp->right;
	}

	return count;
}


//fn to convert a LL to a BST ( Balanced )
node* convertLLToBST(node* &head, int nodes) {

	//base case
	//if LL is empty i.e has 0 nodes
	if (nodes<=0) {
		return NULL;
	}

	//create left subtree and store in left named node
	//assuming nodes/2 as left subtree ( mid-1 logic )

	node* left = convertLLToBST(head, nodes / 2);

	//make root and assign head to it ( mid logic )
	node* root = head;

	//attaching root->left to left node created having left subtree
	root->left = left;

	//move head to right sub tree ( mid+1 logic)
	head = head->right;

	//calculate leftover elements in LL
	//i.e nodes/2  by left sub tree , 1 node as root >>> so these subtracted from nodes in LL will give elements for right subtree
	int arg = (nodes - (nodes / 2)) - 1;
	//right subtree creation
	root->right = convertLLToBST(head, arg);

	//returning root
	return root;

}



//main result returning fn
node* mergeBST(node* root1, node* root2) {
	// Write your code here.

	//creating 2 heads to get two doubly linked lists
	node* head1 = NULL;
	node* head2 = NULL;

	//convert two trees to linked lists
	convertToDLL(root1, head1);
	convertToDLL(root2, head2);

	//merging two obtained linked list to one LL
	node* head = mergeLL(head1, head2);

	//converting the mergedLL to a BST
	node* newRoot = convertLLToBST(head, nodeCounter(head));

	//returning obtained new root
	return newRoot;
}


















int main() {



	return 0;
}

