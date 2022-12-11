#include<iostream>
#include<vector>
using namespace std;

//recursive fn
int countWays(int n, int i) {

	//base case
	if (i == n) {
		return 1;
	}
	//base case
	if (i > n) {
		return 0;
	}

	//rec call and returns
	return (countWays(n, i + 1) + countWays(n, i + 2));

}



int main() {

	//input
	int n = 3;
	//our iterator
	int i = 0;

	//ans fetcher
	int ans = countWays(n, i);

	//printing answer
	cout << ans << endl;

	return 0;
}

//dp solution

/* 
int countWays(int n, int i, vector<int>& dp) {

    if (i == n) {
        return 1;
    }

    if (i > n) {
        return 0;
    }

    if (dp[i] != -1) {
        return dp[i];
    }


    dp[i] = (countWays(n, i + 1, dp) + countWays(n, i + 2, dp)) % MOD;
    return dp[i];
}


int countDistinctWays(int nStairs) {
    //  Write your code here.

    vector<int> dp(nStairs + 1, -1);

    int ans = countWays(nStairs, 0, dp);

    return ans;





}*/