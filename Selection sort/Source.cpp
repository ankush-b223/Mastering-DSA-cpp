#include <iostream>
using namespace std;

void selectionSort(int arr[], int size) {

    int count, test, min;

    for (count = 0; count < size; ++count) {
        min = count;

        for (test = count + 1; test < size; ++test) {

            if (arr[min] > arr[test]) {
                min = test;
            }
        }

        int temp = arr[count];
        arr[count] = arr[min];
        arr[min] = temp;
    }
}



int main() {

    int array[100] = { 5,6,2,4,2,8 };

    selectionSort(array, 6);

    cout << "The sorted array is" << endl;
    for (int count = 0; count < 6; ++count) {
        cout << array[count] << endl;
    }

    return 0;
}