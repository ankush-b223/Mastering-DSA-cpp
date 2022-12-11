#include <iostream>
using namespace std;

//queue class definition
class queue {

	int* arr;
	int front;
	int rear;
	int size;

public:

	//constructor
	queue() {
		size = 100001;
		arr = new int[size];
		front = -1;
		rear = -1;
	}


	//isempty or not fn def
	bool isEmpty() {
		if (front == -1) {
			return true;
		}
		else {
			return false;
		}

	}

	//pushes data to circular queue
	void push(int data) {

		//isfull?
		if (front == 0 && rear == size-1){
			cout << "Queue is full" << endl;
			return;
		}
		else if (rear == (front - 1) % (size - 1)) {
			cout << "Queue is full" << endl;
			return;
		}

		//if queue is empty
		else if (isEmpty()) {  //if emepty initialize both pointer variables
			front = rear = 0;
		}

		// rear at end & front !=0  //cyclic nature
		else if (rear == size - 1 && front != 0) {
			rear = 0;
			
		}

		//normal flow
		else {
			rear++;
			
		}

		//push data
		arr[rear] = data;

	}

	//remove element
	void pop() {

		//isempty?
		if (isEmpty()) {
			cout << "Queue is empty" << endl;
		}
		
		//deallocating element
		arr[front] = -1;

		//single element operation makes queue empty so put pointers -1
		if (front == rear) {
			front = rear = -1;
		}


		//front at end //cyclic nature
		else if (front == size - 1) {
			front = 0;
		}

		//normal flow
		else {
			front++;

		}
	}

	//returns front element
	int peek() {
		return arr[front];
	}

};



//driver code
int main() {

	queue *q = new queue();

	q->push(10);
	q->push(20);

	q->pop();
	cout << q->peek() << endl;




	return 0;
}