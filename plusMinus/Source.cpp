#include <iostream>
using namespace std;

void plusMinus(int arr[100] , int n) {

    int count;
    float positive = 0, zero = 0, negative = 0;

    for (count = 0; count < n; ++count) {
        if (arr[count] == 0) {
            zero += 1;
        }
        else if (arr[count] > 0) {
            positive += 1;
            
        }
        else {
            negative += 1;
        }

    }

    float positive_ratio = positive / n;
    float zero_ratio = zero / n;
    float negative_ratio = negative / n;

    cout << positive_ratio << endl;
    cout << negative_ratio << endl;
    cout << zero_ratio << endl;

}


int main() {

    int n, count,array[100];
    cout << "Enter array size" << endl;
    cin >> n;

    cout << "enter array elements" << endl;
    for (count = 0; count < n; ++count) {
        cin >> array[count];
    }

    plusMinus(array, n);










    return 0;
}
