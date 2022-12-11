#include <iostream>
using namespace std;

int pivot(int arr[] , int size) {

	int start = 0;
	int end = size - 1;
	int mid = start + (end - start) / 2;

	while (start < end) {

		if (arr[mid] >= arr[0]) {
			start = mid + 1;
		}
		else {
			end = mid;
		}

		mid = start + (end - start) / 2;

	}

	return start;




}






int main() {

	int array[100] = { 12,15,16,3,5,7 };

	cout << "The pivot of the given array is " << pivot(array, 6);

	return 0;
}