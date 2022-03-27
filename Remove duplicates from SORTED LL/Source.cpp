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
	if (head->next == NULL) {
		head->next = new_node;
		return;
	}

	node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = new_node;

}

void print(node*& head) {
	node* temp = head;
	while(temp!=NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}

}

void remove_duplicates(node*& head) {
	
	node* temp = head;
	if (temp == NULL) {
		return;
	}
	if (temp->next == NULL) {
		return;
	}

	
	node* then;
	while (temp->next != NULL) {

		if (temp->data == temp->next->data) {
			then = temp->next->next;
			temp->next = then;

			//if duplicate is there dont change temp value run it again
			continue;
		}
		
		temp = temp->next;
		
	}

}






int main() {

	node* head = NULL;

	append(head, 1);
	append(head, 1);
	append(head, 1);
	append(head, 2);
	append(head, 3);
	append(head, 3);
	append(head, 4);

	print(head);
	cout << endl;
	remove_duplicates(head);
	print(head);

	return 0;
}