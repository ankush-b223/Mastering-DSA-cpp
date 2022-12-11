#include <iostream>
using namespace std;

//function definition
void bubbleSort(int arr[], int size) {

	//check the args well
	for (int count = 1; count <= size; ++count) {

		//this loop only for ignoring last element i.e size-count , else count is not req
		//swapping checker 
		bool swapped = false;

		//test<size-count coz , last element is getting sorted with every pass/roound
		for (int test = 0; test < size - count; ++test) {

			if (arr[test] > arr[test + 1]) {
				swap(arr[test], arr[test + 1]);
				//update swapped
				swapped = true;
			}
		}

		//if no swap , arr already sorted , break  return array.
		if (swapped == false) {
			break;
		}

	}

}







//driver code
int main() {

	int array[100] = { 2,5,1,3,7,1,9 };

	bubbleSort(array, 7);

	for (int count = 0; count < 7; ++count) {
		cout << array[count] << endl;
	}


	return 0;
}