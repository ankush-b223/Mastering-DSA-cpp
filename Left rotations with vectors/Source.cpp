#include <iostream>
#include <vector>
using namespace std;

vector<int> rotateLeft(int d, vector<int> arr) {
    vector<int> result;
    int length = arr.size();
    int count, test, temp;

    for (count = 0; count < d; ++count) {
        temp = arr[0];
        for (test = 0; test < length; ++test) {
            arr[test ] = arr[test + 1];
            
        }
        arr[length - 1] = temp;
    }

    return arr;
}


int main() {

    vector<int> array{ 1,2,3,4,5 };
    int d;
    cin >> d;
    vector<int> result = rotateLeft(d, array);

    int count;
    for (count = 0; count < 5; ++count) {
        cout << result[count];
    }



	return 0;
}