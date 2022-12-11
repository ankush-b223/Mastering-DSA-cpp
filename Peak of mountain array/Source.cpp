#include <iostream>
using namespace std;


//no key req
int peak(int arr[], int size) {

	int start = 0;
	int end = size - 1;

	int mid = start + (end - start) / 2;

	//note no <= onlyy < otherwise it will go on infinite loop
	while (start < end) {

		//two cases 
		if (arr[mid] < arr[mid + 1]) {
			//start is going to be answer variable
			start = mid + 1;
		}
		else  {
			end = mid;
		}
		
		mid = start + (end - start) / 2;

	}

	return start;


}





int main() {

	int array[100] = { 1,3,3,5,3,1 };

	int answer = peak(array, 6);
	cout << "the peak in the given mountain is " <<answer <<" or " <<array[answer]<<" as the exact element"<<endl;



	return 0;
}