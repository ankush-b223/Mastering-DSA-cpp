#include<iostream>
#include<stack>
using namespace std;


void insertAtBottom(stack<int>& stck, int data) {

	//base case
	if (stck.empty()) {
		//stck here is empty so push the data ( bottom )
		stck.push(data);

		//return
		return;
	}


	//store and keep aside
	int top = stck.top();

	//pop
	stck.pop();
	//recursive call
	insertAtBottom(stck, data);

	//while returning push back kept aside stored element ( top )
	stck.push(top);

}



int main() {

	//input stack
	stack<int> initialStck;

	//input data
	int data;

	//fn call	
	insertAtBottom(initialStck, data);

	//return given stack

	return 0;
}