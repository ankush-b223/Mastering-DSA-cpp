#include<iostream>
#include<vector>
using namespace std;

int solve(int n, int k) {
    //base case
    if (n == 1) {
        //return 0 as for 1 element in mod range first node is 0
        return 0;
    }

    //solve for n-1 , k ) add k to it ( recurrence relation ) and check if the answer is in mod(%) range by % n
    return (solve(n - 1, k) + k) % n;

}

int findTheWinner(int n, int k) {
    //mod is in 0-based indexing so +1 to the ans [as the qs to 1 -> range]
    int ans = solve(n, k) + 1;

    //return
    return ans;
}

int main() {

    //inputs
    int n;
    int k;

    //fn call 
    int ans = findTheWinner(n, k);

    //printing
    cout << ans;


	return 0;
}