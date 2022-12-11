#include<iostream>
#include<vector>
using namespace std;


int countWays(int n, int i) {

	if (i == n) {
		return 1;
	}

	if (i > n) {
		return 0;
	}

	return (countWays(n, i + 1) + countWays(n, i + 2));

}



int main() {

	int n = 2;
	int i = 0;

	int ans = countWays(n, i);

	cout << ans << endl;

	return 0;
}