#include <iostream>
using namespace std;

int main() {

	int array[100], count,checker;

	cout << "Enter array checker";
	cin >> checker;
	
	cout << "Enter array elements";
	for (count = 0; count < checker; ++count) {

		cin >> array[count];

	}

	cout << "the input array is " <<endl;

	for (count = 0; count < checker; ++count) {
		cout << array[count] << endl;
	}







	return 0;
}