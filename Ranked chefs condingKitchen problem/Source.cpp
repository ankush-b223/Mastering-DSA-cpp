#include <iostream>
using namespace std;

bool possible(int arr[], int size, int dishes, int mid) {

	int timeSum = 0;

	for (int count=0; count < size; ++count) {

		timeSum += arr[count];
		


	}

}


int minTime(int arr[], int size, int dishes) {

	int start = 0;
	int sum = 0;

	for (int count = 0; count < size; ++count) {
		sum += arr[count];
	}

	int end = sum;

	int mid = start + (end - start) / 2;
	int answer = -1;

	while (start <= end) {

		if (possible(arr, size, dishes, mid)) {
			answer = mid;


		}
		else {


		}

		mid = start + (end - start) / 2;


	}

	return answer;

}



int main() {


	int ranks[100] = {1,2,3,4};
	int dishes = 11;
	int size = 4;

	cout << minTime(ranks, size, dishes);

	return 0;
}