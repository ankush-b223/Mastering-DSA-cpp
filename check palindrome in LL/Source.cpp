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



int ispallindrome(node*& head) {

	int count = 0;
	node* temp = head;

	while (temp != NULL) {
		++count;
		temp = temp->next;
	}

	int freq = count / 2;

	count = 1;

	temp = head;
	while (count < freq) {

		temp = temp->next;
		++count;

	}

	node* middle = temp;

	//setting head2 from mid node
	node* head2 = middle->next;
	
	

	//reversing from middle node
	node* prev = NULL;
	node* then = NULL;
	node* curr = head2;


	while (curr != NULL) {

		then = curr->next;
		curr->next = prev;
		prev = curr;

		curr = then;

	}

	head2 = prev;

	int flag=1;
	temp = head;
	curr = head2;

	while (temp != head2 && curr != NULL) {

		if (temp->data != curr->data) {
			flag = 0;
			return flag;
		}

		temp = temp->next;
		curr = curr->next;

	}




	return flag;

	
}
















int main() {


	node* head = NULL;

	append(head, 6);
	append(head, 7);
	append(head, 8);
	append(head, 8);
	append(head, 7);
	append(head, 6);

	print(head);
	cout << endl;

	cout << ispallindrome(head);

	return 0;
}