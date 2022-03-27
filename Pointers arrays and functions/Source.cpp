#include <iostream>
using namespace std;


void take_array(int array[100], int check) {

	for (int count = 0; count < check; ++count) {

		cin >> array[count];

	}

}

void display_array(int arr[100],int check) {
	
	int* ptr2 = arr;
	
	for (int count = 0; count < check;++count) {
		cout << "Element " << count + 1 << " = " << *(ptr2 +count) << endl;
	}
	
}


int main() {


	int count, checker, array[100];
	


	cout << "Enter array size " << endl;
	cin >> checker;

	cout << "Enter array elements " << endl;
	
	take_array(array, checker);

	display_array(array,checker);



	return 0;
}