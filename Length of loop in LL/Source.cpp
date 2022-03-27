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

int loop_counter(node* slow_p) {

	node* temp = slow_p->next;
	int counter = 1;
	while (temp != slow_p) {
		++counter;
		temp = temp->next;
	}

	return counter;
}

int detect_loop_print_length(node*& head) {

	node* slow = head;
	node* fast = head;

	while (slow != NULL && fast->next != NULL) {

		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {

			return loop_counter(slow);
		}

	}
	return 0;

}










int main() {
	//initializing LL with head
	node* head = NULL;

	//pushing elements into LL
	push(head, 25);
	push(head, 20);
	push(head, 15);
	push(head, 10);
	push(head, 5);


	//creating a loop in LL
	head->next->next->next->next->next = head->next;

	int result = detect_loop_print_length(head);
	cout << "The length is " << result << endl;
	


	return 0;
}













