#include <iostream>
using namespace std;

//partition fn places partition element in crrct index
//makes left side elements less than partition and vice versa
int partition(int arr[], int start, int end) {

	//assuming pivot as the first start element
	int pivot = arr[start];
	//initialising counter
	int counter = 0;

	//checking for the count of elements smaller than pivot
	for (int count = start + 1; count <= end; ++count) {
		if (pivot >= arr[count]) {
			++counter;
		}
	}

	//calculating correct index of pivot element
	int pivotIndex = start + counter;

	//placing pivot element in correct index
	swap(arr[pivotIndex], arr[start]);


	//initializing two pointing variables one from start (i) & the other from end(j)
	int i = start;
	int j = end;

	//loop till i doesnt reach pivotIndex or j does the same
	while (i<pivotIndex && j>pivotIndex) {

		//if left element is already smaller than pivotIndex element increment i (move forward)
		if (arr[i] <= arr[pivotIndex]) {
			i++;
		}
		//if right element is already bigger than pivot element decrement j ( move back )
		else if (arr[j] > arr[pivotIndex]) {
			j--;
		}
		//check condition again and swap i j and also post increment & decrement it
		if (i<pivotIndex && j>pivotIndex) {
			swap(arr[i++], arr[j--]);
		}
	}
	
	//return index of partiition element
	return pivotIndex;

}


//quicksort recursive fn def
void quickSort(int arr[], int start, int end) {

	//base case
	if (start >= end) {
		return;
	}

	//the variable part stores the partition element's correct index (i.e pivotIndex) returned
	int part = partition(arr, start, end);

	//partition is already in crrct index

	//sort the left side of partition
	quickSort(arr, start, part - 1);
	//sort the right side of partition
	quickSort(arr, part + 1, end);


}







//driver code
int main() {

	int array[100] = { 5,7,2,7,8,1 };
	int size =6;
	
	quickSort(array, 0, size - 1);

	for (int count = 0; count < size; count++) {
		cout << array[count] << endl;
	}

	return 0;
}