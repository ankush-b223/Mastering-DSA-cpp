#include <iostream>
using namespace std;

//done in codestudio , map approach awaited
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
	if (head == NULL) {
		return;
	}
	do {
		cout << temp->data << " ";
	} while (temp != head);

}

void append(node* head, int new_data) {

	node* new_node = new node(new_data);
	node* temp = head;
	while (temp != NULL) {
		temp = temp->next;
	}
	temp->next = new_node;

}










int main() {


	return 0;
}