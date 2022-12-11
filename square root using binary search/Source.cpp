#include <iostream>
using namespace std;

int squareRoot(int input) {

	int start = 0;
	int end = input;
	int mid = start + (end - start) / 2;
	int answer = -1;


	while (start <= end) {

		if ((mid * mid) == input) {
			return mid;
		}
		else if ((mid * mid) > input) {
			end = mid - 1;
		}
		else {
			answer = mid;
			start = mid + 1;
		}

		mid = start + (end - start) / 2;


	}

	return answer;

}


double precision(int number, int tempSol) {

	double answer = tempSol;
	double factor = 1;



}







int main() {

	int num = 99;

	cout << "The answer is " << squareRoot(num) << endl;

	return 0;
}