#include <iostream>
using namespace std;

void twosum(int nums[100], int target) {
    int count, test, checker = 0;
    int length = sizeof(nums) / sizeof(nums[0]);

    for (count = 0; count < length; ++count) {
        for (test = count + 1; test < length; ++test) {
            if (nums[count] + nums[test] == target) {
                cout << count << " " << test;
                checker = 1;
                break;
            }

        }
        if (checker == 1) {
            break;
        }

    }
   

}

void main() {

    int array[100] = { 2,7,11,15 };
    int target = 9;

    twosum(array, target);

}