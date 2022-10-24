#include<iostream>
#include<queue>
#include<vector>
using namespace std;





int minCost(int input[], int size) {

	//initializing total sum variable
	int sum = 0;

	//making min heap
	priority_queue<int , vector<int> , greater<int> > pq;

	//pushing all array elements to min heap
	for (int i = 0; i < size; ++i) {
		pq.push(input[i]);
	}

	//till the size of the min heap is greater than 1

	//logic is remove top 2 make their sum and push the sum
	//on the add the two's sum to the totalSum too
	while (pq.size() > 1) {
		
		//fetch top 2 elements ( min coz min heap) then pop it
		int num1 = pq.top();
		pq.pop();

		int num2 = pq.top();
		pq.pop();

		//make their sum
		int twoSum = num1 + num2;
		//update total sum
		sum += twoSum;

		//push the twoSum to the heap
		pq.push(twoSum);
	}

	return sum;
}









int main() {
	
	//input array
	int input[100] = { 4, 3, 2, 6 };

	//size of it
	int size = 4;

	//ans fetching from fn call
	int ans = minCost(input, size);

	//printing
	cout << ans << endl;


	return 0;
}