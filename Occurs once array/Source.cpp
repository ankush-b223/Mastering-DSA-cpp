#include <iostream>
using namespace std;


int occursOnce(int arr[100], int n) {
    int freq[100];
    int count, test, frequency = 0;
    int result=0;
    for (count = 0; count < n; ++count) {
        frequency = 0;
        for (test = count + 1; test < n; ++test) {

            if (arr[count] == arr[test]) {
                frequency += 1;
            }

        }
        
        frequency = freq[count];

    }

    for (count = 0; count < n; ++count) {
        if (freq[count] == 1) {
            arr[count] = result;
            break;
        }
    }

    return result;

}

void main() {

    int count, array[100], checker;
    int result;
    cout << "Enter array size" << endl;
    cin >> checker;

    for (count = 0; count < checker; ++count) {
        cin >> array[count];
    }

  
    result = occursOnce(array, checker);

    cout << result;
  

}