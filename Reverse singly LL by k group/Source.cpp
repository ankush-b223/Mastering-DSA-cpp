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


void print(node* &head) {
	node* temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}


node* reverse_byK(node* &head,int k) {
	
	//base case
	if (head == NULL) {
		return NULL;
	}
	
	//reversing k group {upto k elements}
	node* temp = head;
	node* prev = NULL;
	node* then = NULL;
	int  count = 0;

	while (temp != NULL && count<k) {
		then = temp->next;

		temp->next = prev;
		prev = temp;

		temp = then;
		++count;

	}

	//recursive call
	if (then != NULL) {

		//head-> next coz , i want to attach the recursively attained resultant LL to the next of head
		head-> next = reverse_byK(then, k);
	} 

	//returning prev pntr
	return prev;

}





int main() {

	int count;
	node* head = NULL;

	for (count = 1; count <= 8; ++count) {
		append(head, count);
	}

	print(head);
	cout << endl;

	node* result = reverse_byK(head, 2);

	print(result);

	return 0;
}