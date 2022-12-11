#include<iostream>
#include<stack>
#include<vector>
using namespace std;


void solve(vector<int>& input, vector<int>& ans, stack<int>& stck) {

	//push -1 as its the case for last element
	stck.push(-1);

	//traverse vector from right -> left
	for (int count = input.size() - 1; count >= 0; count--) {

		//fetch element
		int element = input[count];

		//till the top of stack has an element bigger than that of element
		while (stck.top() > element) {
			//pop!
			stck.pop();
		}

		//here stck.top is < element
		//put to ans
		ans[count] = stck.top();

		//push the element whose next smaller element we found out just now
		stck.push(element);
		

	}

}


int main() {

	//input vector
	vector<int> input = { 1, 2, 4 ,3 };
	int size = input.size();

	//creating answer vector
	vector<int> ans(size);

	//req ds
	stack<int> stck;

	//solve call
	solve(input, ans, stck);

	//printing answer
	for (auto i : ans) {
		cout << i << " ";
	}
	cout << endl;



	return 0;
}