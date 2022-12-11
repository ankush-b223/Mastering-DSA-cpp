#include <iostream>
using namespace std;

//checking if the mid number is a possible solution
bool possible(int arr[], int size, int students, int mid) {

	//student counter
	int studentCount = 1;
	//sum of pages
	int pagesum=0;


	//loop
	for (int count = 0; count < size; ++count) {


		//condition 1
		if (pagesum + arr[count] <= mid) {
			pagesum += arr[count];
		}

		//condition 2
		else {
			//go to next sudent
			studentCount += 1;
			//check if going outbound of range or not
			if (studentCount > students || arr[count] > mid) {
				return false;
			}
			//update pagesum for new student 
			pagesum = arr[count];

		}
	}
	
	return true;
}

//allocating function
int allocate(int arr[], int size, int students) {


	int start = 0;

	int sum = 0;

	//square root logic , getting the range of search space
	for (int count = 0; count < size; ++count) {
		sum += arr[count];
	}

	int end = sum;

	int mid = start + (end - start) / 2;

	//initialising answer variable to store answer
	int answer = -1;

	//loop starts
	while (start <= end) {

		//if solution exists go to eft to check for more min soluion
		if (possible(arr, size, students, mid)) {
			answer = mid;
			end = mid - 1;
		}
		//go to right portion
		else {
			start = mid + 1;
		}

		//update mid
		mid = start + (end - start) / 2;

	}
	//returning the min possible solution as answer
	return answer;
}





//driver code
int main() {

	int books[100] = { 10,20,30,40 };
	int student = 2;
	int size = 4;


	int answer = allocate(books, size, student);

	cout << answer << endl;

	return 0;
}