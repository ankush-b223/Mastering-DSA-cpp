#include <iostream>
using namespace std;

//function def takes arr , size of array , and key which number to be searched
int binarySearch(int arr[], int size, int key) {

	//marking start and end
	int start = 0;
	int end = size - 1;

	//calculating mid , this formula is to avoid integer out of range error
	int mid = start + (end - start) / 2;

	//loop start , note the condition
	while (start <= end) {

		//3 conditions , match , left , right
		//match
		if (arr[mid] == key) {
			return mid;
		}

		//right
		if (key>arr[mid]) {
			start = mid + 1;
		}

		//left
		else {
			end = mid - 1;
		}

		//update mid with new start /end
		mid = start + (end - start) / 2;

	}

	//if element not there in array
	return -1;

}


//driver code
int main() {

	int odd[100] = { 1,3,5,7,9 };
	int even[100] = { 2,4,6,8 };

	int evenAns = binarySearch(even, 4, 9);
	int oddAns = binarySearch(odd, 5, 34);

	cout << "Even answer is " << evenAns << endl;
	cout << "Odd answer is " << oddAns << endl;



	return 0;
}