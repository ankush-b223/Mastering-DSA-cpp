#include <iostream>
using namespace std;

//pivot finding fn
int pivot(int arr[], int size) {

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

	//returns pivot index
	return start;

}

//binary search with start & end as args 
int binarySearch(int arr[], int start,int end, int key) {

	int mid = start + (end - start) / 2;

	while (start <= end) {
		if (arr[mid] == key) {
			return mid;
		}
		else if (arr[mid] > key) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}

		mid = start + (end - start) / 2;

	}

	return -1;
}

//condition searching fn
int pivotSearch(int arr[], int size, int key) {

	//getting pivot of arr
	int pivo = pivot(arr, size);

	//condition 
	if (key<=arr[size-1] && key>=arr[pivo]) {
		//calling binary search
		return binarySearch(arr, pivo, size - 1, key);
	}
	else {
		//same 
		return binarySearch(arr, 0, pivo-1, key);
		
	}

}




int main() {

	int array[100] = { 15,17,2,4,6 };

	int ans = pivotSearch(array, 5,17);

	cout << array[ans] <<" is there in array at index "<<ans << endl;

	return 0;
}