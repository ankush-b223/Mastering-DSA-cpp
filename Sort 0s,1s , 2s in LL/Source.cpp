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

void insert_end(node*& tail, node* temp) {

	tail->next = temp;
	tail = temp;

}


void sort(node*& head) {

	node* zero_head = new node(-1);
	node* zero_tail = zero_head;

	node* one_head = new node(-1);
	node* one_tail = one_head;

	node* two_head = new node(-1);
	node* two_tail = two_head;


	node* temp = head;
	while (temp != NULL) {

		if (temp->data == 0) {
			insert_end(zero_tail, temp);
		}
		else if (temp->data == 1) {
			insert_end(one_tail, temp);
		}
		else if (temp->data == 2) {
			insert_end(two_tail, temp);
		}
		
		temp = temp->next;

	}
	
	if (one_head->next == NULL) {
		zero_tail->next = two_head->next;
	}
	else {
		zero_tail->next = one_head->next;
		one_tail->next = two_head->next;
	}
	two_tail->next = NULL;

	head = zero_head->next;
	 
	delete(zero_head);
	
	delete(one_head);
	
	delete(two_head);
	

	


}






int main() {

	node* head = NULL;

	append(head,1);
	append(head,2);
	append(head,2);
	append(head,0);
	append(head,1);

	print(head);
	cout << endl;

	sort(head);
	print(head);





	return 0;
}