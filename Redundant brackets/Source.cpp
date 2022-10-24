#include<iostream>
#include<stack>
using namespace std;


bool isRedundant(string exp, stack<char>& stck) {

    //traverse the exp
    for (int i = 0; i < exp.length(); i++) {

        //fetch curr charecter from the expression
        char ch = exp[i];


        //if opening bracket
        if (ch == '(' || ch == '{' || ch == '[') {
            stck.push(ch);
        }

        //if operator
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            stck.push(ch);
        }
        //ending bracket
        else if (ch == ')' || ch == '}' || ch == ']') {

            //fetch top
            char elem = stck.top();
            //if top was operator
            if (elem == '+' || elem == '-' || elem == '*' || elem == '/') {
                //pop it 
                stck.pop();

                //remove all operators from top
                while (stck.top() != '(') {
                    stck.pop();
                }

                //remove the first '(' corr to ch ==')'
                stck.pop();

                //no redundancy in this case
            }
            else {
                //no operator so redundant brackets
                return true;
            }

        }



    }

    //no redundancy
    return false;
}



int main() {

    //input expression
	string exp;

    //req ds
	stack<char> stck;

    //ans calling by fn 
    bool ans = isRedundant(exp, stck);





	return 0;
}