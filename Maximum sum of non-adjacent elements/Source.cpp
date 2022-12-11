#include<iostream>
#include<vector>
using namespace std;

//rev fn
int solve(vector<int>& nums, int index) {

	//base cases
	if (index < 0) {
		return 0;
	}
	if (index == 0) {
		return nums[0];
	}

	//fetch ans by including current index & excluding it
	int including = solve(nums, index - 2) + nums[index];
	int excluding = solve(nums, index - 1) + 0;

	//track max sum
	int ans = max(including, excluding);

	return ans;
}



//memoization fn
int solveM(vector<int> &nums, int index, vector<int> &dp) {
	
	//base cases
	if (index < 0) {
		return 0;
	}
	if (index == 0) {
		return nums[0];
	}

	//dp check
	if (dp[index] != -1) {
		return dp[index];
	}

	//fetch answers
	int including = solveM(nums, index - 2, dp) + nums[index];
	int excluding = solveM(nums, index - 1, dp) + 0;

	//store obtained ans in dp by curr index
	dp[index] = max(including, excluding);

	//return stored dp value for index
	return dp[index];
}



//tabulation fn
int solveT(vector<int>& nums, int index) {

	int n = nums.size();

	//make dp array
	vector<int>dp(n + 1, -1);

	//base case analysis
	dp[0] = nums[0];

	//loop for 1 -> last index which is index by arg call
	for (int count = 1; count < n; ++count) {

		//including excluding logic
		int including = dp[count  - 2] + nums[count];
		int excluding = dp[count - 1] + 0;

		//store the values in dp array
		dp[count] = max(including, excluding);

	}

	//return dp value by index
	return dp[index];
}




//space optimised fn
int solveS(vector<int>& nums, int index) {

	int n = nums.size();

	//replace dp by these pointers
	int prev2 = 0;
	int prev1 = nums[0];

	//loop
	for (int count = 1; count < n; ++count) {

		// smae logic
		int including = prev2 + nums[count];
		int excluding = prev1 + 0;

		//track max with maxi
		int maxi = max(including, excluding);

		//shift the two varaibles for next iteration
		prev2 = prev1;
		prev1 = maxi;

	}

	//return maxi as stored by prev1
	return prev1;
}






int main() {
	

	vector<int> nums = { 2, 1, 4, 9 };

	int size = nums.size();

	//int ans = solve(nums , size-1 );

	//cout << ans << endl;



	//memoization

	/*
	vector<int> dp(size + 1, -1);

	int ans = solveM(nums, size - 1, dp);

	cout << ans << endl;
	*/

	//tabulation


	int ans = solveT(nums, size-1);

	cout << ans << endl;


	//space optimized
	//solveS




	return 0;
}