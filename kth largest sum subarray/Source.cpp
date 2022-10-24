#include<iostream>
#include<queue>
using namespace std;


int kLargestSubArray(vector<int>& arr, int size, int k) {

	//making a min heap
	priority_queue<int, vector<int>, greater<int> > minHeap;
	
	//accessing all the subArrays of the given input array
	for (int count = 0; count < size; ++count) {
		//re-initializing sum with 0 for each incremenet in outer loop
		int sum = 0;

		for (int test = count; test < size; ++ test) {
			//incremnet sum
			sum += arr[test];

			//if the minheap doesnt yet have k eeleemnts then jsut push whatever sum is coming in
			if (minHeap.size() < k) {
				minHeap.push(sum);
			}
			//here 
			//min heap already has k elements in it
			//we need the kth largest => we need the minheap to have the largest K elements

			else {
				//so if the sum coming in is bigger than the top push in else move to next increment
				if (sum > minHeap.top()) {
					//pop exisiting top
					minHeap.pop();
					//push sum
					minHeap.push(sum);

				}
			}


		}

	}

	//here the minheap has largest k elements as the sum of subarrays 
	//as minheap so the top will have the min of k largest >> which is the answer
	return minHeap.top();

}





//drier code
int main() {

	//inputs
	vector<int> input = { 1, 2, 3 };
	int size = 3;
	int k = 1;

	//stores ans from fn call
	int ans = kLargestSubArray(input, size, k);

	//printing ans
	cout << ans << endl;

	return 0;
}