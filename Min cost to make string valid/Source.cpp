#include<iostream>
#include<stack>
using namespace std;

int main() {

	//input string
	string exp;

	//returning answer
	int answer;

	//if the length of the string is odd so answer is impossible 
	if (exp.length() % 2 == 1) {
		answer = -1;
		//-1 is returned
	}

	//creating req ds
	stack<char> stck;
	
	//traversing the expression giving
	for (int i = 0; i < exp.length(); ++i) {

		//remove the already valid sub expressions

		//fetch the curr character
		char ch = exp[i];

		//if opening bracket
		if (ch == '{') {
			stck.push(ch);
		}
		//closing bracket
		else {

			//valid exists so pop it 
			if (!stck.empty() && stck.top() == '{') {
				stck.pop();
			}
			//not valid so push the closing bracket too
			else {
				stck.push(ch);
			}
		}
	}

	//here the stack has all the brackets invalid ( or the ones which need to be reversed )

	//counters

	//a -> count of opening brackets
	//b->  count of closing brackets

	int a = 0, b = 0;

	//traverse the stack
	while (!stck.empty()) {

		//if opening bracket
		if (stck.top() == '{') {
			//increment a
			a++;
		}
		else {
			//closing bracket
			b++;
		}
		//pop!
		stck.pop();
	}

	//answer formula
	answer = (a + 1) / 2 + (b + 1) / 2;





	//return the answer




	return 0;
}