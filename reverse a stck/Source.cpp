#include<iostream>
#include<stack>
using namespace std;

//insertAtbottom fn logic
void insertAtBottom(stack<int>& stck, int data) {

	//base case
	if (stck.empty()) {
		
		//empty stack so push element (bottom)
		stck.push(data);

		return;
	}



	int top = stck.top();

	stck.pop();

	//recursive call
	insertAtBottom(stck, data);

	//while returning..
	stck.push(top);

}



void reverseStack(stack<int> &stck) {

	//base case
	if (stck.empty()) {
		return;
	}

	//fetch top & keep aside
	int top = stck.top();
	
	//pop
	stck.pop();

	//recursive call
	reverseStack(stck);

	//while returning put back element in the bottom of the stck
	insertAtBottom(stck, top);

}



int main() {
	
	//input stack
	stack<int> inputStck;


	//fn call
	reverseStack(inputStck);




	return 0;
}