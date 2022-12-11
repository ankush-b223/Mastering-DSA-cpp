#include <iostream>
using namespace std;

//merge arrays sortedly fn def
void merge(int arr[], int start, int end) {

	//calculating mid to get len of new arrays
	int mid = start + (end - start)/2;

	//cacuating length of new arrays
	int len1 = (mid - start) + 1;
	int len2 = end - mid;

	//making 2 new arrays to split 2 original arr
	int* first = new int[len1];
	int* second = new int[len2];

	//copying content of Actual array to copy1 arr (start to mid)
	int temp = start;
	for (int count = 0; count < len1; ++count) {

		first[count] = arr[temp];
		temp++;

	}

	//copying content of actual array to copy2 arr(mid+1 to end)
	temp = mid + 1;
	for (int count = 0; count < len2 ; ++count) {

		second[count] = arr[temp];
		temp++;

	}

	//merging 2 sorted arrays
	int index1 = 0, index2 = 0, mainIndex = start;

	//putting in element whichever is smaller by comparing 
	while (index1 < len1 && index2 < len2) {

		if (first[index1] < second[index2]) {

			arr[mainIndex] = first[index1];
			mainIndex++;
			index1++;
		}

		else {
			arr[mainIndex] = second[index2];
			mainIndex++;
			index2++;
		}


	}

	//checking for leftover elements in copy arr1
	while (index1 < len1) {

		arr[mainIndex] = first[index1];
		mainIndex++;
		index1++;
	}

	//checking for leftover elements in copy arr2
	while (index2 < len2) {

		arr[mainIndex++] = second[index2++];
	}


	//original array is splitted into two new copy arrays.
	//conent is copied splittingly to copy arrays
	//copy arrays are merged sortedly to give sorted original array
	//returned original array sortedly

}

//recursive fn def
void mergeSort(int arr[], int start , int end ) {

	//generating mid to break the arrays
	int mid = start + (end - start) / 2;

	//base case 
	if (start >= end) {
		return;
	}

	//call for left part array
	mergeSort(arr, start, mid);
	//call for right part array 
	mergeSort(arr, mid + 1, end);

	//merge small arrays sortedly 
	merge(arr, start, end);


}



//driver code
int main() {

	int array[100] = { 3,2,6,8,4,8,9 };
	int size = 7;

	mergeSort(array, 0, 5);

	for (int count = 0; count < size; count++) {
		cout << array[count] << endl;
	}

	return 0;
}