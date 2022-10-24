#include<iostream>
#include<stack>
using namespace std;


void insertSorted(stack<int> &stck, int top) {

	//base case
	if (stck.empty()) {
		
		//stack is empty
		//s put the value it will be sorted

		stck.push(top);
		
		return;
	}



	//if the element to put is smaller than top of curr stack
	if (stck.top() > top) {

		//fetch the top & keep aside
		int element = stck.top();
		//pop it
		stck.pop();

		//recursive call
		insertSorted(stck, top);

		//as the stack coming will be sorted so just simply push back the kept aside element
		stck.push(element);
	}
	//element >= stck.top
	else {
		//just push as underlying stack is already sorted
		stck.push(top);
	}



}




void sortStack(stack<int> &stck) {

	//base case
	if (stck.empty()) {

		return;
	}

	//keep top element aside
	int top = stck.top();

	//pop
	stck.pop();

	//recursive call
	sortStack(stck);

	//while returning inserting kept aside top in a sorted manner 
	insertSorted(stck, top);

}


int main() {

	//input
	stack<int> inputStck;


	//fn call
	sortStack(inputStck);


	return 0;
}