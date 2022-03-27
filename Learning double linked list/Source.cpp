#include <iostream>
using namespace std;

class node {

	public:
		int data;
		node* next;
		node* prev;

};

void push(node* &head, int new_data) {

	node* new_node = new node();

	new_node->data = new_data;
	new_node->next = head;
	new_node->prev = NULL;

	head->prev = new_node;

	head = new_node;

}

void print(node* input) {

	node* temp = input;

	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}

}

void insert_after(node* prev_node, int new_data) {

	//taking care of exception if prev_node is NULL
	if (prev_node == NULL) {
		cout << "Given node can't be NULL" << endl;
	}
	
	node* new_node = new node();


	new_node->data = new_data;
	new_node->next = prev_node->next;
	new_node->prev = prev_node;
	if (prev_node->next != NULL) {
		prev_node->next->prev = new_node;
	}

	prev_node->next = new_node;

	//insert after last node error debug

}


void append(node* &head,int new_data) {
	node* new_node = new node();
	new_node->data = new_data;
	new_node->next = NULL;

	node* temp = head;

	if (head == NULL) {
		new_node->prev = NULL;
		head = new_node;
		return;
	}

	while (temp->next != NULL) {
		temp = temp->next;
	}

	temp->next = new_node;
	new_node->prev = temp;

}


void insert_before(node* &head,node* given_node, int new_data) {

	if (given_node == NULL) {
		cout << " Error";
		return;
	}

	node* new_node = new node();

	new_node->data = new_data;
	new_node->next = given_node;

	if (given_node->prev == NULL) {
		new_node->prev = NULL;
		given_node->prev = new_node;
		head = new_node;
		return;
	}

	new_node->prev = given_node->prev;

	given_node->prev->next = new_node;
	given_node->prev = new_node;


}

void delete_head(node* &head) {

	node* temp = head;
	head->next->prev = NULL;
	head = temp->next;


}

void delete_pos_node(node* &head, int n) {
	//error ,debug needed
	if (n <= 0) {
		cout << "Wrong Input" << endl;
		return;
	}

	node* temp = head;
	int count;

	if (n == 1) {
		head = head->next;
		return;
	}

	for (count = 1; temp != NULL && count < n; ++count) {
		temp = temp->next;
	}

	if (temp == NULL) {
		cout << "Error , n exceeds no of nodes in the LL " <<count<< endl;
		return;
	}

	temp->next->prev = temp->prev;
	temp->prev->next = temp->next;




}



void main() {

	//making three nodes
	node* first = new node();
	node* second = new node();
	node* third = new node();

	//assigning them data , next pntr & prev pntr
	first->data = 1;
	first->next = second;
	first->prev = NULL;

	second->data = 2;
	second->next = third;
	second->prev = first;


	third->data = 3;
	third->next = NULL;
	third->prev = second;

	//assigning head
	node* head = first;

	

	

	//Pushing 0 in the first place and changing head
	push(head, 0);


	

	//inserting 0 after third node
	insert_after(third, 0);

	//appending 0 to the LL
	append(head, 1);

	//printing LL
	print(head);

	cout << endl;

	

	insert_before(head ,third, 0);

	//delete_head(head);

	

	delete_pos_node(head, 5);

	//printing updated LL
	print(head);
}

