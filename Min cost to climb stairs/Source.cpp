#include<iostream>
#include<vector>
using namespace std;

//normal recursion
int minCost(vector<int>& cost, int n) {

    //base cases
	if (n == 0) {
		return cost[0];
	}
	if (n == 1) {
		return cost[1];
	}

    //rec calls as recurrence relation
	int ans = cost[n] + min(minCost(cost, n - 1), minCost(cost, n - 2));


	return ans;

}

//rec + memoization (dp)
int minCost2(vector<int>& cost, int n, vector<int>& dp) {

    //base cases
    if (n == 0) {
        return cost[0];
    }
    if (n == 1) {
        return cost[1];
    }

    //check if call was already asnwered
    if (dp[n] != -1) {
        return dp[n];
    }

    //store new calls in dp array
    dp[n] = cost[n] + min(minCost2(cost, n - 1, dp), minCost2(cost, n - 2, dp));

    //return newly stored value
    return dp[n];

}



//driver code
int main() {

    //input
	vector<int> cost = { 10,15,20 };

    //destination
	int n = cost.size();

    //dp array
    vector<int> dp(n + 1, -1);


	//int ans = min(minCost(cost, n - 1), minCost(cost, n - 2));




	//tabulation

    dp[0] = cost[0];
    dp[1] = cost[1];

    for (int count = 2; count < n; ++count) {
        dp[count] = cost[count] + min(dp[count - 1], dp[count - 2]);
    }


    int ans3 = min(dp[n - 1], dp[n - 2]);



    //space optimisation in tabulation

    /*
    int prev2 = cost[0];
    int prev1 = cost[1];

    for (int count = 2; count < n; ++count) {

        int curr = cost[count] + min(prev1, prev2);

        //dp[count] = cost[count] + min(dp[count-1], dp[count-2]);    

        prev2 = prev1;
        prev1 = curr;

    }



    return min(prev1, prev2);

    */
	return 0;
}