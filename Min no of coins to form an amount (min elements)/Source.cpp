#include<iostream>
#include<vector>
using namespace std;

//normal recursion soloution
int minCost(vector<int> num, int x) {

	//base cases
	if (x == 0) {
		return 0;
	}

	if (x < 0) {
		return INT_MAX;
	}
	
	//answer returner ( always stores the min 
	int mini = INT_MAX;

	//loop to fetch all calls for all respective coin denominations
	for (int count = 0; count < num.size(); ++count) {

		//call for each coin denomination
		int ans = minCost(num, x - num[count]);

		//if the ans is not coming as INT_MAX ( ans came from where x was negative which is not valid so exclude such cases
		if (ans != INT_MAX) {
			//get the min b/w stored mini & curr ans fro curr iteration call
			mini = min(mini, 1 + ans);
		}

	}

	//return stored mini
	return mini;
}


//recursion plus memoization
int minCostM(vector<int> num, int x , vector<int> &dp) {

	//base cases
	if (x == 0) {
		return 0;
	}

	if (x < 0) {
		return INT_MAX;
	}

	//check if call is already stored in dp array
	if (dp[x] != -1) {
		return dp[x];
	}

	//same mini tracker
	int mini = INT_MAX;

	for (int count = 0; count < num.size(); ++count) {

		//fetch answers iteratively 
		int ans = minCostM(num, x - num[count], dp);

		if (ans != INT_MAX) {
			mini = min(mini,1+ ans);
		}

		//get the mini
	}

	//store that in dp array
	dp[x] = mini;

	return dp[x];
}




//tabulation fn 
int minCostT(vector<int> num, int x) {

	//create dp array
	vector<int> dp(x + 1, INT_MAX);

	//base case analysis
	dp[0] = 0;

	//loop through all possible values of target amount ( x here ) 
	for (int count = 1; count <= x; ++count) {

		//stores diff target amount answers in dp array

		//for each target array iteratively call for all denominations
		for (int test = 0; test < num.size(); ++test) {
			
			//if the index req is positive && the dp[ans] coming is not from negative (INT_MAX) 
			if (count - num[test] >= 0 && dp[count - num[test]] != INT_MAX) {

				//get the min
				dp[count] = min(dp[count], 1 + dp[count - num[test]]);
			
			}

		}
	}
	
	//if negative return -1
	if (dp[x] == INT_MAX) {
		return -1;
	}

	//return dp value for target amount x
	return dp[x];

}


//no space optimization is possible since we have to loop through all the denominations for all req target amounts


int main() {

	int x = 7;

	vector<int> num = {1,2,3};

	//normal rec sol

	/*
	int ans = minCost(num, x);

	cout << ans << endl;
	*/




	//rec + memoization

	/* 
	vector<int> dp(x + 1, -1);

	int ans = minCostM(num, x, dp);


	cout << ans << endl;
	*/





	//tabulation

	int ans = minCostT(num, x);

	cout << ans<< endl;




	return 0;
}
