#include <iostream>
#include <map>
#include <unordered_set>

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


void remove_duplicates(node*& head) {

	if (head == NULL || head->next == NULL) {
		return;
	}

	node* temp = head;
	node* prev = NULL;
	//creation of unordered set
	unordered_set<int> visited;

	while (temp != NULL) {
		//.find return value if found else returns last element
		if (visited.find(temp->data) != visited.end())  {

			prev->next = temp->next;
			
			temp = temp->next;
			
			continue;
		}
		else {

			visited.insert(temp->data);
			prev = temp;
			temp = temp->next;


		}
	}
	

}









int main() {


	node* head = NULL;

	append(head,1);
	append(head,1);
	append(head,4);
	append(head,5);
	append(head,1);
	append(head,2);
	append(head,5);

	print(head);

	cout << endl;

	remove_duplicates(head);
	print(head);


	return 0;

}