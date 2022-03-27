#include <iostream>
using namespace std;


class node {
	public:
		int data;
		node* next;
};

//prints a LL function
void print(node* address) {

	while (address != NULL) {
		cout << address->data << " ";
		address = address->next;
	}

}

//inserting new node at front in a LL
void push(node* &head,int new_data) {

	//creating new node
	node* new_node = new node();
	//assigning data and pointer
	new_node->data = new_data;
	new_node->next = head;
	//making a new head
	head = new_node;

}

void insert_after(node* prev_node, int new_data) {
	

	node* new_node = new node();

	new_node->data = new_data;
	new_node->next = prev_node->next;

	prev_node->next = new_node;
}

void append(node*& head, int new_data) {

	node* new_node = new node();

	new_node->data = new_data;
	new_node->next = NULL;


	node* last = head;

	if (head->next == NULL) {
		head->next = new_node;
		head = new_node;
	}
	else{

		while (last->next != NULL) {
			last = last->next;
		}

		last->next = new_node;
	}

}


void delete_node(node*& head, int key) {

	node* temp = head;
	node* prev = NULL;

	if(head != NULL && head->data == key) {
		head = temp->next;
		delete temp;
	}

	else{

		while (temp != NULL && temp->data != key) {
			prev = temp;
			temp = temp->next;
		}

		if (temp == NULL) {
			return;
		}
		else {
			prev->next = temp->next;
			delete temp;
		}
	}

}

void delete_pos_node(node*& head, int position) {

	node* temp = head;
	int count;

	if (position == 0) {
		head = temp->next;
		free(temp);
	}
	else{
		for (count = 0; temp->next != NULL && count < position - 1; ++count) {
			temp = temp->next;
		}

		node* after = temp->next->next;

		free(temp->next);

		temp->next = after;
	}
}






void main() {

	

	//creation of nodes for LL
	node* first = NULL;
	node* second = NULL;
	node* third = NULL;

	//allocating memory to nodes
	first = new node();
	second = new node();
	third = new node();

	//assigning data and next pointers to each freshly created node
	first->data = 1;
	first->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;

	//appointing head of th LL
	node* head = first;
	
	//pushing 0 in the top of LL
	push(head, 0);

	//inserting 4 after third node
	insert_after(third, 4);

	//appending 5 to the LL
	append(head, 5);

	//insert_after(third, -1);

	//printing updated LL
	//print(head);

	//cout << endl;

	//delete_node(head, 0);

	

	//insert_after(third, 0);
	print(head);

	delete_pos_node(head, 0);

	cout << endl;

	print(head);




}