#include <iostream>
using namespace std;

class queue {

	int* arr;
	int front;
	int rear;
	int size;

public:

	queue() {
		size = 1000001;
		arr = new int[size];
		front = -1;
		rear = -1;
	}



	bool isEmpty() {

		if (front == -1) {
			return true;
		}

		else {
			return false;
		}

	}

	bool isFull() {

		if (front == 0 && rear == size - 1) {
			return true;
		}
		//check args well
		else if (front != 0 && rear == (front - 1) % (size - 1)) {
			return true;
		}

		else {
			return false;
		}

	}



	//new fn 
	//pushing in front with front pointer and moving front pointer back --
	void pushFront(int data) {

		//isempty
		if (isEmpty()) {
			front = rear = 0;

		}


		//isfull
		else if (isFull()) {
			cout << "Queue is full";
			return;
		}



		//cyclic
		else if (front == 0 && rear != size - 1) {
			front = size - 1;
		}



		//normal
		else {
			front--;
		}

		arr[front] = data;

	}


	void pushRear(int data) {

		//ifempty
		if (isEmpty()) {

			front = rear = 0;
			//arr[rear] = data;

		}

		//isfull

		else if (isFull()) {

			cout << "Queue is full" << endl;
			return;

		}

		//if last element cyclic

		else if (front != 0 && rear == size - 1) {
			rear = 0;
			//arr[rear] = data;
		}


		//normal
		else {
			rear++;
		}

		arr[rear] = data;


	}


	void popFront() {

		//isempty
		if (isEmpty()) {
			cout << "Queue is empty" << endl;
		}

		arr[front] = -1;

		//single element // very imp check args front ==rear
		if (front== rear ) {
			front = rear = -1;
		}

		//cyclic
		else if (front == size-1 ) {
			front = 0;
		}

		//normal
		else {
			front++;
		}



	}

	//new fn
	//popping from the back using rear pointer and moving rear backwards --
	void popRear() {

		//isempty
		if (isEmpty()) {
			cout << "Queue is emmpty" << endl;
		}

		arr[rear] = -1;

		//single element /// very imp check args front ==rear
		if (front == rear ) {
			front = rear = -1;
		}
		//cyclic.
		else if (rear==0) {
			rear = size - 1;
		}

		//normal
		else {
			rear--;
		}



	}



	int getFront() {

		//edge case check for empty
		if (isEmpty()) {
			return -1;
		}
		
		return arr[front];
	}

	int getRear() {


		//edge case check for empty
		if (isEmpty()) {
			return -1;
		}
		return arr[rear];
	}

	
};





//driver code

int main() {

	queue* q = new queue();

	q->pushRear(10);
	q->pushRear(20);
	q->pushRear(30);

	q->popFront();

	cout << q->getRear() << endl;
	cout << q->getFront() << endl;


	return 0;
}