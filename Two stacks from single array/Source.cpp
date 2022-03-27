#include <iostream>
using namespace std;

class stack {

public:
	int size;
	int top1;
	int top2;
	int* arr;

	stack(int s) {
		this->size = s;
		
		top1 = -1;

		//traversing & initializing stack2 form behind i.e from size
		top2 = s;

		arr = new int[size];

	}

	void push1(int data) {

		if (size - top1 > 1) {
			++top1;
			arr[top1] = data;
			return;
		}

		cout << "Stack overflow" << endl;

	}

	void pop1() {
		if (top1 >= 0) {
			--top1;
			return;
		}

		cout << "stack Underflow" << endl;

	}

	void push2(int data) {

		if (size - top1 > 1) {
			//right->left traversal 
			--top2;
			arr[top2] = data;
			return;
		}

		cout << "Stack overflow" << endl;

	}

	void pop2() {
		if (top1 >= 0) {
			//risht->left traversal
			++top2;
			return;
		}

		cout << "stack Underflow" << endl;
	}

	int peek1() {
		return arr[top1];

	}

	int peek2() {
		return arr[top2];

	}

};




int main() {

	stack stck(10);

	int count,data=1;
	for (count = 0; count < 5; ++count) {
		stck.push1(data);
		++data;
	}

	stck.push2(10);
	stck.push2(9);

	

	cout << stck.peek1() << endl;
	cout << stck.peek2() << endl;

	return 0;
}