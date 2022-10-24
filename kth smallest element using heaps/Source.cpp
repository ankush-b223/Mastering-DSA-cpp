#include<iostream>
#include<queue>
using namespace std;


int kSmallest(vector<int>& input, int size, int k) {

	//creating a max heap
	priority_queue<int> pq;

	//pushing the first k elements to the heap
	for (int count = 0; count < k; ++count) {
		pq.push(input[count]);
	}

	//traversing through the rest of elements present in  input array 
	for (int count = k; count < size; ++count) {
		int element = input[count];

		//if the element as in current iteration is smaller in value than the element stored as the top in heap 

		//then swap 
		if (element < pq.top()) {
			//remove the top
			pq.pop();
			//push the element found to be smaller
			pq.push(element);
		}
	}
	//here the heap has k elements
	//since a max heap so its top will store the max of the k elements
	//which is req as ans k SMALLEST

	//vice versa logic with min heap for k largest element

	return pq.top();


}





int main() {

	//input vector
	vector<int> input = { 7, 10, 4, 3, 20, 15 };
	int size = 6;

	//value of k
	int k = 3;

	//answer storing from fn call
	int ans = kSmallest(input, size, k);

	//printing ans
	cout << ans << endl;

	return 0;
}