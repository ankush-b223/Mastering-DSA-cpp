#include <iostream>
using namespace std;


//possible fn
bool possible(int arr[], int size, int woodReq, int mid) {

	//woodDown is the wood collected
	int woodDown = 0;
	//this variable takes the amount of wood cut and adds to woodCoolected (woodDown)
	int difference = -1;

	//loop starts
	for (int count = 0; count < size; ++count) {

		//if the tree is smaller than cutting height ignore and go to next iterattion or next tree
		if (mid >= arr[count]) {
			continue;
		}
		//take the difference and add it to woodDown 
		difference = arr[count] - mid;

		woodDown += difference;
	}

	//if woodReq is achieved return true else false
	if (woodDown >= woodReq) {
		return true;
	}
	else {
		return false;
	}

}

int height(int arr[], int size, int woodReq) {

	//binary search logic with search space
	int start = 0;
	int sum = 0;

	for (int count = 0; count < size; ++count) {
		sum += arr[count];
	}

	int end = sum;

	int mid = start + (end - start) / 2;
	int answer = -1;

	while (start <= end) {

		//if answer is received go to right of mid to find more efficient answer if exist 
		if (possible(arr, size, woodReq, mid)) {
			//storing current mid value to answer variable
			answer = mid;
			start = mid + 1;
		}
		//go left of mid
		else {
			end = mid - 1;
		}
		//update mid 
		mid = start + (end - start) / 2;
	}

	return answer;
}




int main() {

	int trees[100] = {4,42,40,26,46};
	int woodReq = 20;

	cout << height(trees, 5, woodReq)<<endl;

	return 0;
}