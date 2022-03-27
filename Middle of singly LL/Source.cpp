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


void append(node*& head,int new_data) {

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

void print(node*& head) {
	node* temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}

}

void middleLL(node*& head) {

	node* temp = head;
	int count=0;
	if (head == NULL) {
		cout << " LL is empty";
		return;
	}

	while (temp!=NULL) {

		++count;
		temp = temp->next;

	}
	int freq = count;
	temp = head;
	

	if (count % 2 == 1) {
		freq = freq / 2;
		//cout << freq << endl;
		
		for (count = 1; count < freq +1; ++count) {
			temp = temp->next;
		}
		cout << temp->data << " Is the middle of the given LL";
		return;
	}
	freq = freq / 2;
	for (count = 1; count <= freq; ++count) {
		temp = temp->next;
	}
	cout << temp->data << " Is the middle of the given LL";


}




int main() {

	node* head = NULL;

	append(head, 1);
	append(head, 2);
	append(head, 3);
	append(head, 4);
	//append(head, 5);
	//append(head, 6);
	//append(head, 7);

	print(head);
	
	cout << endl;

	middleLL(head);

	

	return 0;
}