#include <iostream>
using namespace std;

//function def
void SelectionSort(int arr[], int size) {

	//initializing req variables
	int min = -1;
	int temp = -1;

	

	for (int count = 0; count < size; ++count) {

		//assuming the ith(count) element as min as of yet
		min = count;

		for (int test = count + 1; test < size; ++test) {

			//if corresponding elements have smaller values min will get updated with the most min index
			if (arr[test] < arr[min]) {
				//min stores the index of the minimum element of list
				min = test;

				
			}
		}

		//swapping min element with ith(count) element
		temp = arr[count];
		arr[count] = arr[min];
		arr[min] = temp;

	}



}



//driver code
int main() {

	int array[100] = { 2,7,4,9,8,3 };

	SelectionSort(array, 6);

	for (int count = 0; count < 6; ++count) {
		cout << array[count] << endl;
	}

	return 0;
}