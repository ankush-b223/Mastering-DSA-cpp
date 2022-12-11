#include <iostream>
using namespace std;

int leftOccur(int arr[],int size,int key) {

	int start = 0;
	int end = size - 1;

	int mid = start + (end - start) / 2;

	int answer = -1;

	while (start <= end) {

		if (arr[mid] == key) {
			answer = mid;
			end = mid - 1;
		}

		else if (arr[mid] > key) {
			end = mid - 1;
		}
		else if (arr[mid] < key) {
			start = mid + 1;
		}

		mid = start + (end - start) / 2;

	}

	return answer;

}


int rightOccur(int arr[], int size, int key) {

	int start = 0;
	int end = size - 1;

	int mid = start + (end - start) / 2;

	int answer = -1;

	while (start <= end) {

		if (arr[mid] == key) {
			answer = mid;
			start = mid + 1;
		}

		else if (arr[mid] > key) {
			end = mid - 1;
		}
		else if (arr[mid] < key) {
			start = mid + 1;
		}

		mid = start + (end - start) / 2;

	}

	return answer;

}





int main() {
	
	int arr[100] = { 1,2,3,3,3,3,5,7 };


	//total occurrences = [right most instance index - leftmost instance index] , add 1 (coz index is zero based)
	int totalOccur = (rightOccur(arr, 8, 3) - leftOccur(arr, 8, 3)) + 1;
	cout << "total occurences of 3 is " << totalOccur << endl;
	
	return 0;
}