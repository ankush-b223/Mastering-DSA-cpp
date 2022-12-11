#include<iostream>
#include<vector>
using namespace std;






int solve(vector<int> trim, int index) {

	if (index == 0) {
		return trim[0];
	}

	if (index < 0) {
		return  0;
	}


	int including = solve(trim, index -2) + trim[index];
	int excluding = solve(trim, index - 1);

	int ans = max(including, excluding);

	return ans;

}


int solveM(vector<int> trim, int index , vector<int> &dp) {

	if (index == 0) {
		return trim[0];
	}

	if (index < 0) {
		return  0;
	}

	if (dp[index] != -1) {
		return dp[index];
	}

	int including = solveM(trim, index - 2,dp) + trim[index];
	int excluding = solveM(trim, index - 1,dp);

	dp[index] = max(including, excluding);

	return dp[index];

}




int solveT(vector<int> trim, int index) {

	int size = trim.size();

	vector<int> dp(size + 1, -1);

	dp[0] = trim[0];

	for (int count = 1; count < size; ++count) {

		int including = dp[count - 2] + trim[count];
		int excluding = dp[count - 1] + 0;

		dp[index] = max(including, excluding);
	}


	return dp[index];

}

//only this is accepted
int solveS(vector<int> trim, int index) {

	int size = trim.size();

	//base case analaysis
	int prev2 = 0;
	int prev1 = trim[0];

	//loop form 1-> end of trim
	for (int count = 1; count < size; ++count) {
		//call
		int including = prev2 + trim[count];
		int excluding = prev1 + 0;

		int ans = max(including, excluding);

		prev2 = prev1;
		prev1 = ans;
	}


	return prev1;

}


//driver code
int main() {

	//input
	vector<int> valueInHouse = { 2 ,3 ,2 };

	int size = valueInHouse.size();

	//if only one house case
	if (size == 1) {
		return valueInHouse[0];
	}

	//create 2 vectors
	//one -> first house omitted
	vector<int> first(size);
	//two last house omitted
	vector<int> second(size);

	//this is done since the houses are in a circle so last is adjacent to first & vice versa

	//creating both the vectors
	for (int count = 0; count < size; ++count) {
		if (count != 0) {
			first.push_back(valueInHouse[count]);
		}
		if (count != size - 1) {
			second.push_back(valueInHouse[count]);
		}
	}

	//fetching the sizes of created vectors
	int size1 = first.size();
	int size2 = second.size();

	//making two dp arrays for them
	vector<int> dp1(size1 + 1, -1);
	vector<int> dp2(size2 + 1, -1);

	//calling for ans from both created vectors
	int ans1 = solveM(first, size1 - 1,dp1);
	int ans2 = solveM(second, size2 - 1,dp2);

	//final ans is max of fetched answers
	int ans = max(ans1, ans2);

	cout << ans << endl;


	return 0;
}