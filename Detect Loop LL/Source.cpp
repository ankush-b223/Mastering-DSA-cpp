#include <iostream>
using namespace std;


class node {

public:
	int data;
	node* next;

	node(int d) {
		this->data = d;
		this->next = NULL;
	}

};


void print(node*& head) {
	node* temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}

}

void push(node*& head, int new_data) {
	
	node* new_node = new node(new_data);
	
	if (head == NULL) {
		head = new_node;
		return;
	}

	new_node->next = head;
	head = new_node;



}

bool detect_loop(node*& head) {

	node* slow = head;
	node* fast = head;

	while (slow!=NULL  && fast->next!=NULL) {
		
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {

			return true;
		}

	}
	return false;

}









int main() {
	//initializing LL with head
	node* head = NULL;
	//int count;

	//pushing elements into LL
	push(head, 25);
	push(head, 20);
	push(head, 15);
	push(head, 10);
	push(head, 5);

	
	//creating a loop in LL
	head->next->next->next = head->next;

	if (detect_loop(head)==true) {
		
		cout << "Loop there "<<endl;
	}
	else {
		cout << "Loop not there";
	}
	

	return 0;
}