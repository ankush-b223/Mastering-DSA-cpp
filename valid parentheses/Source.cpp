#include<iostream>
#include<stack>
using namespace std;




bool matches(char ch, char top) {

	//closing bracket matching
	if (ch == ']' && top == '[') {
		return true;
	}

	if (ch == '}' && top == '{') {
		return true;
	}

	if (ch == ')' && top == '(') {
		return true;
	}

	//no condition entered so false
	return false;

}


bool solve(string expression , stack<char> &stck) {

	//traverse the entire expression
	for (int count = 0; count < expression.length(); ++count) {

		//fetch curr character
		char ch = expression[count];

		//if an opening bracket
		if (ch == '[' || ch == '{' || ch == '(') {
			//push
			stck.push(ch);
		}
		//if closing bracket
		else if (ch == ']' || ch == '}' || ch == ')') {
			
			//check whether the stck is already empty or not
			if (!stck.empty()) {
				//if top exists
				//call matches fn
				if (matches(ch, stck.top())) {
					//match valid 
					//pop top
					stck.pop();
				
				}
				//did not match with stack's top so false
				else {
					return false;
				}
			}
			//closing bracket exists but stck empty => not valid exp
			else {
				return false;
			}
		}//any other than brackets => false
		else {
			return false;
		}

	}

	//after traversal if the stack is empty
	if (stck.empty()) {
		//true
		return true;
	}
	//false
	else {
		return false;
	}


}




int main() {
	
	//input expression
	string expression = "[()]{}{[()()]()}" ;

	//req ds
	stack<char> stck;

	//ans def & fn call
	bool ans = solve(expression , stck);

	//printing ans
	if (ans) {
		cout << "Valid" << endl;
	}
	else{
		cout << "Not valid" << endl;
	}



	return 0;
}