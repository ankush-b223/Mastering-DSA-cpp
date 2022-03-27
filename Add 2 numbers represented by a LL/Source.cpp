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
		cout << temp->data << ' ';
		temp = temp->next;
	}


}


int sumLL(node*& head) {

	int sum = 0;
	node* temp = head;

	while (temp != NULL) {
		sum += temp->data;
		temp = temp->next;
	}

	return sum;
}







int main() {

	node* head = NULL;
	node* head2 = NULL;

	append(head,3);
	append(head,4);

	append(head2,2);
	append(head2,3);
	append(head2,0);


	print(head);
	cout << endl;
	print(head2);
	cout << endl;

	int res = sumLL(head2);
	cout << res;

	return 0;
}