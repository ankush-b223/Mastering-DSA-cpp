#include <iostream>
using namespace std;


class node {

public:
	int data;
	node* next;
};


void print(node* &head) {

	node* temp = head;
	if (head == NULL) {
		return;
	}
	do {
		cout << temp->data << " ";
	} while (temp != head);

}

void push(node* &head, int new_data) {

	node* temp = head;
	node* new_node = new node();


	new_node->data = new_data;

	if (head == NULL) {
		new_node->next = new_node;
		
	}
	else {


		

		while (temp->next != head) {

			temp = temp->next;

		}

		temp->next = new_node;
		new_node->next = head;

	}

	head = new_node;
}




int main() {

	node* head = NULL;

	push(head, 1);
	push(head, 2);
	push(head, 3);

	print(head);



	return 0;
}