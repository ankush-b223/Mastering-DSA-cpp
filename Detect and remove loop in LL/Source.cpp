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



void append(node* &head,int new_data) {
	
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


void detect_removeLoop(node*& head) {

	node* slow = head;
	node* fast = head;
	int flag = 0;
	
	while (slow != NULL && fast->next != NULL && flag!=1) {
		
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			flag = 1;
		}
	}
	
	if (flag == 0) {
		cout << "no loop found" << endl;
		return;
	}

	node* temp = slow->next;
	int counter = 1;
	while (temp != slow) {
		++counter;
		temp = temp->next;
	}
	
	
	int count;
	node* ptr1 = head;
	node* ptr2 = head;
	
	for (count = 0; count < counter; ++count) {
		
		ptr2 = ptr2->next;
	}
	

	
	
	while (ptr1 != ptr2) {
		
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;

	}
	

	
	for (count = 1; count < counter; ++count) {
		
		ptr2 = ptr2->next;
	}
	
	
	ptr2->next = NULL;
	
	



}










int main() {

	node* head = NULL;

	int count;
	for (count = 1; count <= 5; ++count) {
		append(head, count);
	}

	print(head);
	cout << endl;

	//loop creation 
	head->next->next->next->next->next = head->next;

	
	detect_removeLoop(head);

	print(head);

	return 0;
}