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

void append(node*& head, int new_data) {

	node* new_node = new node(new_data);

	if (head == NULL) {
		head = new_node;
		return;
	}

	node* temp = head;

	while (temp->next != NULL) {
		temp = temp->next;
	}

	temp->next = new_node;

	


}



void reverseLL(node* &head) {

	node* temp = head;
	node* prev = NULL;
	node* then = NULL;

	while (temp != NULL) {

		then = temp->next;

		temp->next = prev;
		prev = temp;

		temp = then;

	}
	head = prev;

}



void printLL(node* &head) {

	node* temp = head;

	while (temp != NULL) {
	
		cout << temp->data << " ";
		
		
		temp = temp->next;
	}

}	






int main() {

	

	node* head = NULL;

	append(head, 1);
	append(head, 2);
	append(head, 3);

	printLL(head);

	cout << endl;

	reverseLL(head);

	
	printLL(head);




	return 0;
}