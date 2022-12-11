#include<iostream>
#include<vector>
using namespace std;

//class def
class NStack {

public:
	//data members

	//the main arr
	int* input;

	//the top arr

	//stores the top of all stacks
	int* top;


	//the next arr


	//this next array functions as a pointer to the prev element of a top in a stack ( if elements are pushed already )
	//otherwise it tracks towards the next freeSpaces our freeSpace pointer can be to insert future elements

	//the next array
	int* next;
	//the freeSpot pointer (curr iteration)
	int freeSpot;

	//size of main array , value of N >> no of stacks  (respectively)
	int S, N;


	//constructor
	NStack(int N, int S) {

		//initialize the data members
		this->N = N;
		this->S = S;

		this->input = new int[S];

		//size of top vector is value of N
		this->top = new int[N];

		this->next = new int[S];

		//initialize the top vector 
		for (int count = 0; count < N; ++count) {
			this->top[count] = -1;
		}
		

		//initialize the next vector
		for (int count = 0; count < S-1; ++count) {
			this->next[count] = count + 1;
		}
		//the last element of next vector
		next[S - 1] = -1;

		//freespot initialization
		this->freeSpot = 0;
		

	}


	//push op in the ds
	bool push(int value , int StackNo) {

		//overflow
		if (freeSpot == -1) {
			//overflow
			return false;
		}

		//the index is where the value is to be pushed 
		//the position where a value is to be pushed is shown by freeSpot pointer
		int index = freeSpot;

		//update freeSpot for next operation using the next array
		freeSpot = next[index];

		//push element to array as an pushing op in stack
		input[index] = value;

		//update the next array index to point towards the prev element at top before pushing new value ( which will become new top now )
		next[index] = top[StackNo - 1];

		//update top
		top[StackNo - 1] = index;

		//return true for a succesfull push
		return true;
	}




	//pop op in this ds
	int pop(int StackNo) {

		//underflow
		if (top[StackNo-1] == -1) {
			//underflow

			return -1;
		}

		//index points towards element to be popped
		int index = top[StackNo - 1];

		//update top to prev element in stack i.e stored in next array in index position
		top[StackNo-1] = next[index];

		//update the next array index to point towards the freeSpot generated due to popping (updation of top)
		next[index] = freeSpot;

		//make the popped element as a freeSpot and allign the pointer to it
		freeSpot = index;

		//return the element popped
		return input[index];

	}



};



//driver code
int main() {

	
	

	return 0;
}