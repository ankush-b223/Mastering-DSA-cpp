#include <iostream>
using namespace std;

//class def (using arrays)
class queue {

		//req variables
		//dynamic array
		int* arr;
		//front pointing var
		int qfront;
		//rear pointing var
		int rear;
		//size of queue
		int size;
public:
			//constructor
			queue() {

				//random big size
				size = 1000000;
				//dynamically creating an array
				arr = new int[size];
				//initializing two pointer variables
				qfront = 0;
				rear = 0;
			}

			//member functions

			//queue empty or not fn
			bool isEmpty() {

				if (qfront == rear) {
					return true;
				}
				else {
					return false;
				}
			}

			//push element to queue
			void push(int data) {

				//checking if queue is full or not
				if (rear == size) {
					cout << "Queue is full" << endl;
				}
				//space there 
				else {
					arr[rear++] = data;
				}
			}

			//remove element from queue
			void pop() {
				//checking for empty
				if (isEmpty()) {
					cout << "Queue is empty" << endl;
				}

				//remove element by making it -1 (null)
				else {
					arr[qfront++] = -1;

					//to optimize space usage 
					if (qfront == rear) {
						qfront = 0;
						rear = 0;
					}
				
				}

			}

			//return first element in queue
			int front() {
				if (isEmpty()) {
					return -1;
				}
				else {
					return arr[qfront];
				}
			}


	
};








//driver code
int main() {

	//making a queue
	queue* q = new queue();

	//pushing elements into queue
	q->push(10);
	q->push(20);
	q->push(30);

	//removing elements from queue
	q->pop();

	//printing
	cout << q->front() << endl;

	return 0;
}