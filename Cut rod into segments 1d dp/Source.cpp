#include<iostream>
#include<vector>
using namespace std;

//rec fn
int solve(int n, int x, int y, int z) {

	//base cases
	if (n == 0) {
		return 0;
	}

	//if n goes negative => the rod cant be cut into segment using given number (x/y/z)
	if (n < 0) {
		//so return negative infinity
		return INT_MIN;
	}

	//try for each segments (x/y/z) 

	//adding one since one cut creates two segments
	int forX = solve(n - x, x, y, z)+1;
	int forY = solve(n - y, x, y, z)+1;
	int forZ = solve(n - z, x, y, z)+1;

	//ans is max of all 33 calls
	int ans = max(forX, max(forY, forZ));
	

	return ans;
}



int solveM(int n, int x, int y, int z , vector<int> &dp) {

	//base cases 
	if (n == 0) {
		return 0;
	}

	if (n < 0) {
		return INT_MIN;
	}

	//dp check
	if (dp[n] != -1) {
		return dp[n];
	}

	//calls
	int forX = solveM(n - x, x, y, z,dp) + 1;
	int forY = solveM(n - y, x, y, z,dp) + 1;
	int forZ = solveM(n - z, x, y, z,dp) + 1;

	//store in dp
	dp[n] = max(forX, max(forY, forZ));

	//return
	return dp[n];
}


int solveT(int n, int x, int y, int z) {

	//initaialize vector by - infinty to hande n < 0 base case
	vector<int> dp(n + 1, INT_MIN);

	//base case analysis
	dp[0] = 0;

	//loop form 1 -> n
	for (int count = 1; count <= n; ++count) {

		//if count - x/y/z is correct index (i.e >= 0) then>>
		if (count - x >= 0) {
			//store the max
			dp[count] = max(dp[count],dp[count - x] + 1);
		}
		if (count - y>= 0) {
			dp[count] = max(dp[count],dp[count - y] + 1);
		}
		if (count - z >= 0) {
			int Z = max(dp[count],dp[count - z] + 1);
		}

		//max keeps getiing tracked 
	}

	//return dp[ n ]
	return dp[n];
}


//driver code
int main() {
	
	//inputs
	int n = 7;
	int x = 5;
	int y = 2;
	int z = 2;

	//dp vector
	vector<int> dp(n + 1, -1);

	//ans call
	int ans = solveM(n, x, y, z,dp);

	//printing
	cout << ans << endl;

	return 0;
}