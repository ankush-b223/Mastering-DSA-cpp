#include<iostream>
#include<stack>
#include<vector>
using namespace std;





int main() {

	//input matrix
	vector<vector<int> > matrix = { {0, 1, 0} , {0, 0, 0} , {0, 1, 0} };

	//size of the matrix or the no of people in party 
	int size =3;

	//req ds
	stack<int> stck;

	//push all the people in party as their index values in matrix given
	for (int count = 0; count < size; ++count) {

		stck.push(count);

	}

	//stack ready

	//till the stack has only one element
	while (stck.size() > 1) {

		//fetch top two number from stack & pop them
		int num1 = stck.top();
		stck.pop();

		int num2 = stck.top();
		stck.pop();

		//if num1 knows num2
		if (matrix[num1][num2] == 1) {
			//num1 cant be celebrity so push num2
			stck.push(num2);
		}
		else {
			//vice versa condition
			stck.push(num1);
		}

	}

	//the only element in stack now is potential candidate to be a celeebrity
	int candidate = stck.top();

	//check the condtions for it being celebrity


	//for candidate knowing no-one do row check in matrix given
	bool rowCheck = false;
	int zeroCount = 0;

	for (int count = 0; count < size; ++count) {

		if (matrix[candidate][count] == 0) {
			++zeroCount;
		}

	}

	if (zeroCount == size) {
		rowCheck = true;
	}


	//for all to know the celebrity condition check column
	bool colCheck = false;
	int oneCount = 0;

	for (int count = 0; count < size; ++count) {

		if (matrix[count][candidate]) {
			++oneCount;
		}

	}

	//the candidate doesnt know itself so 0 in matrix so ignore that in the condition
	//-1 form size logic 

	if (oneCount == size - 1) {
		colCheck = true;
	}





	//if both conditions are true >> potential is a celebrity
	if (colCheck && rowCheck) {
		cout << "Celebrity got = " << candidate << endl;
	}
	else {
		//no celebrity in party
		cout << "No celebrity" << endl;
	}


	return 0;
}

