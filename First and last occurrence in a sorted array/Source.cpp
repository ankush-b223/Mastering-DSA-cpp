#include <iostream>
using namespace std;


//break first left portion & end right portion as two parts


//for left first instance
int leftOccur(int arr[], int size, int key) {

	int start = 0;
	int end = size - 1;
	int mid = start + (end - start) / 2;

	//variable which will store the first instace index after loop 
	int answer = -1;

	while (start <= end) {

		//storing index to variable and updating end to check for more instance on the left side
		//if any more instance is found on left then variable is updated with latest index
		if (arr[mid] == key) {
			answer = mid;
			end = mid - 1;
		}

		//left move
		else if (arr[mid] > key) {
			end = mid - 1;
		}

		//right move 
		else if (arr[mid]<key) {
			start = mid + 1;
		}

		//mid update
		mid = start + (end - start) / 2;

	}

	//returning variable with left most index instance
	return answer;
}



int rightOccur(int arr[], int size, int key) {

	int start = 0;
	int end = size - 1;
	int mid = start + (end - start) / 2;

	int answer = -1;

	while (start <= end) {

		//samne as above just checking the right side with start for last instance
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



	int array[100] = { 1,2,3,3,3,3,3,3,3,3,3,3,3,5 };

	cout << "left first index of 3 is " << leftOccur(array, 14, 3)<<endl;
	
	cout << "right end index of 3 is " << rightOccur(array, 14, 3);

	return 0;
}