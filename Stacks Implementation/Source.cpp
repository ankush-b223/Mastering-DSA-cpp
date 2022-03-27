#include <iostream>
using namespace std;


//creating class of stack using array
class stack {

	//data members
public:
	int size;
	int top;
	int* arr;


	//stack constructor taking size of the array as a parameter/argument
	stack(int s) {


		this->size = s;
		arr = new int[size];
		//top is the index tracker and condition bool for the class
		top = -1;
		
	}

	void push(int data) {

		//size - top if 1 or less then size is full no more data can be pushed ( stack overflow )
		if (size - top > 1) {
			++top;
			arr[top] = data;
		}
		else {
			cout << " Stack Overflow" << endl;
		}

	}


	void pop() {

		//if empty then top -1 ( initial case )
		if (top >= 0) {
			--top;
		}
		else {
			cout << "Stack underflow" << endl;
		}

	}

	//returns top data element present in the stack at that moment 
	int peek() {

		if (top >= 0) {
			return arr[top];
		}
		else {
			cout << "Stack Underflow" << endl;
		}

	}


	//bool to return if stack is empty or not
	bool is_empty() {
		if (top >= 0) {
			return false;
		}
		else {
			return true;
		}
	}

};

int main() {

	//creating stack with the constructor
	stack s(10);

	//pushing elements into the stack s
	s.push(1);
	s.push(2);
	s.push(3);

	//printing top element 
	cout << s.peek() << endl;

	//popping out last element in the stack at that moment
	s.pop();

	cout << s.peek() << endl;

	//bool empty stack fn call
	if (s.is_empty()) {
		cout << "Stack empty" << endl;
	}
	else {
		cout << "Stack is not empty" << endl;
	}


	return 0;
}