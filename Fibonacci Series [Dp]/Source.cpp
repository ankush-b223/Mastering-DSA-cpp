#include<iostream>
#include<vector>
using namespace std;

//recursion & memoization concept [ top - down approach ]
int fib(int term, vector<int> &dpArray) {
	//base case
	if (term <= 1) {
		return term;
	}

	//memoization check ( whether the call's answer is already stored or not )
	if (dpArray[term] != -1) {
		return dpArray[term];
	}
	//recursion call to store the answer in a memoization ds
	dpArray[term] = fib(term - 1, dpArray) + fib(term - 2, dpArray);

	//retrieve answer from meomization ds and return
	return dpArray[term];
}




int main() {

	//input
	int term;
	cin >> term;

	//top down approach

	//a vector used as a memoization ds ( initialized as -1 )
	//vector<int> dpArray(term+1,-1);

	//ans call
	//int ans = fib(term,dpArray);

	//printing
	//cout << ans << endl;




	//bottom down approach
	//tabulation
	
	//tabulation ds is initiated above

	//putting in the base cases to the tabulation ds
	//dpArray[0] = 0;
	//dpArray[1] = 1;

	//loop from 2nd as 0 & 1st term is already inserted  
	//for (int count = 2; count <= term; ++count) {
		//reccurrence realtion
	//	dpArray[count] = dpArray[count - 1] + dpArray[count - 2];
	//}

	//print out answer
	//cout << dpArray[term] << endl;



	//space optimization


	//instead of using the extra space of a vector , replace with a variable
	
	//previous variable pointers
	int prev1 = 1;
	int prev2 = 0;

	//curr sum tracker
	int curr;

	//edge case of 0 as term 
	if (term == 0) {
		cout << 0 << endl;
	}

	//run  from 2-> term
	for (int i = 2; i <= term; ++i) {
		//perform sum
		curr = prev1 + prev2;

		//shifting logic for next iteration
		prev2 = prev1;
		prev1 = curr;
	}

	//as last iteration will be term so print it out 
	cout << prev1 << endl;

	return 0;
}