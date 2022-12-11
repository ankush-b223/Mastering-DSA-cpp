#include <iostream>
using namespace std;


void insertionSort(int arr[], int size) {

	for (int count = 1; count < size; ++count) {

		int key = arr[count];
		//storing previous element to start loop from it
		int test = count - 1;

		//moving back in loop
		while (test >= 0 && arr[test] > key) {
			//right shift
			arr[test + 1] = arr[test];
			--test;
		}

		//inserting sortedly
		arr[test + 1] = key;

	}

}




int main() {

	int array[100] = { 2,7,3,4,8,6 };

	insertionSort(array, 6);

	for (int count = 0; count < 6; ++count) {
		cout << array[count] << endl;
	}




	return 0;
}