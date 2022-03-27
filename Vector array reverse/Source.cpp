#include <iostream>
#include <vector>
using namespace std;

vector<int> reverseArray(vector<int> a) {
    int N = a.size();
    
    vector<int> rev;
    int count, test = 1;

    for (count = N - 1; count >= 0; --count) {
        
        rev.push_back(a[count]);
        ++test;
    }

    return rev;
}




int main() {

    int count;
    vector<int> actual{ 4,3,2,1 };

    vector<int> result = reverseArray(actual);

    for (count = 0; count < result.size(); ++count) {
        cout << result[count];
    }

	return 0;
}