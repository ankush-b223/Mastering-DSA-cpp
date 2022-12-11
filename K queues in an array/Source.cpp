#include <iostream>
using namespace std;

//class def
class kqueue {

public:

	//required data members
	//size of original array
	int size;
	//no of queues
	int k;
	//next free slot to put data in (referenece iterator)
	int free;
	//original array creation
	int* arr;
	//array to store front indexes of all k queues
	int* front;
	//array to rear indexes of all k queues
	int* rear;
	//next data structure which contains the next linking elements or next free indexes (works magic)
	int* next;


	//constructor 
	kqueue(int size, int k) {
		this->size = size;
		this->k = k;

		//initialize free from 0th index
		free = 0;

		//create req arrays
		arr = new int[size];
		next = new int[size];

		front = new int[k];
		rear = new int[k];

		//initializing front and rear array with -1
		for (int count = 0; count < k; ++count) {
			front[count] = -1;
			rear[count] = -1;
		}


		//creating next pointer having single incremented values to initially store all NEXT free indexes
		for (int count = 0; count < size; ++count) {
			next[count] = count + 1;
		}
		//initializing the last element of next array as -1 as no more free index would be available 
		next[size - 1] = -1;

	}

	//pushing 
	void push(int data, int qno) {

		

		//is full? -> overflow>?
		if (free == -1) {
			cout << "No space to push" << endl;
			return;
		}

		//find index
		int index = free;
		//update free to next free slot from next array
		free = next[index];




		//is first element + otherwise
		if (front[qno - 1] == -1) {
			front[qno - 1] = index;
		}
		else {
			//magic of next array stores the linking index
			next[rear[qno - 1]] = index; 

		}



		//update links
		
		next[index] = -1;
		//update rear with new rear index
		rear[qno - 1] = index;



		//push!
		arr[index] = data;

	}

	//pop!
	int pop(int qno) {

		//underflow
		if (front[qno - 1] == -1) {
			cout << "Nothing to pop in given queue" << endl;
			return -1;
		}


		//which index?
		int index = front[qno - 1];


		//update front
		//front moves to next element in given queue with linking given by next array
		front[qno - 1] = next[index];


		//update next
		//this next index will store the value of current free index before popping (link)
		next[index] = free;
		//as after popping the popped index will be first free so free pointer will point towards
		//current freshly popped index aqs it will be free too
		free = index;

		//returning popped element
		return arr[index];

	}


};







int main() {

	kqueue q(10, 3);

	q.push(10, 1);
	q.push(20, 1);
	q.push(30, 2);
	q.push(40, 3);


	cout << q.pop(1) << endl;
	cout << q.pop(1) << endl;
	cout << q.pop(2) << endl;
	cout << q.pop(2) << endl;



	return 0;
}