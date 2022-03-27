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
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}

}

void print_circular(node*& head) {
	cout << head->data << " ";
	node* temp = head->next;
	while (temp != head) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}


void split_centre(node* head) {

	node* temp = head->next;
	int count = 1;

	//getting length of LL
	while (temp != head) {
		++count;
		temp = temp->next;
	}
	
	int test;
	temp = head;
	node* head2;

	//odd-even handling
	if (count % 2 != 0) {
		count += 1;
	}

	//running till middle element
	for (test = 1; test < count / 2; ++test) {
		temp = temp->next;
	}
	head2 = temp->next;
	temp->next = head;

	temp = head2;
	while (temp->next != head) {
		temp = temp->next;
	}
	
	temp->next = head2;


	print_circular(head);
	cout << endl;
	print_circular(head2);
	






}












int main() {

	node* head = NULL;

	append(head, 1);
	append(head, 2);
	append(head, 3); 
	append(head, 4);
	append(head, 5);
	append(head, 6);
	append(head, 7);

	//print(head);
	//cout << endl;

	//creation of circular LL
	node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = head;

	print_circular(head);

	cout << endl;

	split_centre(head);




	return 0;
}