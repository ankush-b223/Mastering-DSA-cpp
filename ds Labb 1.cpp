#include <iostream>
using namespace std;

int main() {

    int arr[100], size, swap;

    cout << "Enter array size followed by its elements " << endl;
    cin >> size;
    int count;

    for (count = 0; count < size; ++count) {

        cin >> arr[count];

    }


    cout << "Enter positions to be swapped (zero indexed)" << endl;
    cin >> swap;

    int temp, swap2;

    for (count = 0; count < size; ++count) {

        if (count == swap) {

            temp = arr[count];
            arr[count] = arr[count + 1];
            arr[count + 1] = temp;


        }

    }


    cout << "Printing new array with swapped numbers" << endl;

    for (count = 0; count < size; ++count) {
        cout << arr[count] << endl;
    }


    return 0;
}







