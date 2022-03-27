#include <iostream>
using namespace std;

void miniMaxSum(int arr[100]) {
    unsigned int temp, count, test;
    for (count = 0; count < 5; ++count) {
        for (test = count + 1; test < 5; ++test) {
            if (arr[count] > arr[test]) {
                temp=arr[count] ;
                arr[count] = arr[test];
                arr[test] = temp;
            }
        }
    }
    unsigned int min_sum = 0;
    for (count = 0; count < 4; ++count) {
        min_sum += arr[count];
    }

    unsigned int max_sum = 0;
    for (count = 1; count < 5; ++count) {
        max_sum += arr[count];
    }

    cout << min_sum << " " << max_sum << endl;

}

int main() {

    cout << "Enter array elements" << endl;

    int count ,array[100];

    for (count = 0; count < 5; ++count) {
        cin >> array[count];
    }

    miniMaxSum(array);

}