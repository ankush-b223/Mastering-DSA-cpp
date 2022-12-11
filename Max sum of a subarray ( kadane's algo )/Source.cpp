#include<iostream>
#include<vector>
using namespace std;

//kadane's algo

//main fn
int maxSumSubArray(vector<int> input) {

	//initialize curr sum tracker & maxSum storing variable
	int sum = 0; 
	//initialiasing maxi with first element of input vector ( can be done with INT_MIN too )
	int maxi = input[0];

	//loop through all elements in input vector
	for (int count = 0; count < input.size(); count++) {

		//update curr sum
		sum += input[count];

		//update max 
		maxi = max(maxi, sum);

		//if sum is negative then re-initialize to 0 & continue
		if (sum < 0) {
			sum = 0;
		}
	}

	//return maxi which is the maxSum of a Subarray
	return maxi;
}




int main() {

	//input

	vector<int> input = { -2,1,-3,4,-1,2,1,-5,4 };

	//fn call
	int ans = maxSumSubArray(input);

	//printing
	cout << ans;




	return 0;
}