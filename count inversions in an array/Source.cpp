#include <iostream>
using namespace std;


int merge(int arr[], int start, int end) {

	int mid = start + (end - start) / 2;

	int len1 = (mid - start) + 1;
	int len2 = end - mid;

	int* first = new int[len1];
	int* second = new int[len2];

	int mainArrIndex = start;
	for (int count = 0; count < len1; ++count) {
		first[count] = arr[mainArrIndex++];

	}

	mainArrIndex = mid + 1;
	for (int count = 0; count < len2; ++count) {

		second[count] = arr[mainArrIndex++];

	}

	//DECLARING INVERSION COUNTER
	int inversions = 0;
	int index1 = 0, index2 = 0;
	mainArrIndex = start;

	while (index1 < len1 && index2 < len2) {

		if (first[index1] < second[index2]) {
			arr[mainArrIndex++] = first[index1++];
		}
		//THE RIGHT ELEMENT IS BIGGER THAN LEFT ELEMENT
		//SO ALL THE ELEMENTS BIGGER THAN CURRENT INDEX2 WILL FORM PAIRS
		//HENCE ALL THE ELEMENTS LEFT IN FIRST ARRAY ARE ADDED AS ALL WILL FORM INVERSION PAIRS
		else {
			arr[mainArrIndex++] = second[index2++];
			//MAIN STEP
			inversions += (len1 - index1);
		}
	}

	while (index1 < len1) {
		arr[mainArrIndex++] = first[index1++];
	}

	while (index2 < len2) {
		arr[mainArrIndex++] = second[index2++];
	}

	//RETURN THE STEP
	return inversions;
}








//MERGE SORT WILL RETURN VALUES INT TYPE
int mergeSort(int arr[], int start, int end) {

	int mid = start + (end - start) / 2;
	int answer = 0;

	//BASE CASE RETURNING 0;
	if (start >= end) {
		return 0;
	}

	//ANSWERS ARE GETTING STORED FROM ALL CALLS
	answer += mergeSort(arr, start, mid);
	answer += mergeSort(arr, mid + 1, end);

	answer += merge(arr, start, end);

	//ANSWER RETURNED
	return answer;

}






int main() {

	int array[100] = { 5,4,3,2,1 };
	int size = 5;

	int inv = mergeSort(array, 0, size - 1);

	cout << inv << endl;

	return 0;
}