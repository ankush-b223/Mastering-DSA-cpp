#include <iostream>
using namespace std;


bool possible(int arr[], int size, int painters, int mid) {

	int painterCount = 1;
	int paintSum = 0;
	
	for (int count = 0; count < size; ++count) {

		if (paintSum + arr[count] <= mid) {
			paintSum += arr[count];
		}

		else {
			painterCount += 1;
			if (painterCount > painters) {
				return false;
			}

			else if (arr[count]>mid) {
				//cout << "false" << endl;
				return false;
			}
			paintSum = 0;
			paintSum += arr[count];
			
		}
	}

	return true;


}

int partition(int arr[], int size, int painters) {

	int start = 0;

	int sum = 0;
	for (int count = 0; count < size; ++count) {
		 sum += arr[count];
	}
	int end = sum;
	
	int mid = start + (end - start) / 2;

	

	int answer = -1;

	while (start <= end) {

		if (possible(arr, size, painters,mid)) {
			answer = mid;
			end = mid - 1;
			
		}

		else {
			start = mid + 1;
		}
		mid = start + (end - start) / 2;
	}

	return answer;
}



int main() {

	int array[100] = { 1,2,3,4};
	int painters = 2;

	cout<<partition(array, 4, 2)<<endl;


	return 0;
}
