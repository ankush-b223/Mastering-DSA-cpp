#include <iostream>
using namespace std;

int main() {

	//c type explicit casting 

	int num;
	double num_d;

	cout << "Enter an integer ";
	cin >> num;

	num_d = (double)num ;

	cout << "The double version of your input " << endl;
	cout << num_d << endl;



	//function style type casting

	int input;
	double input_d;

	cout << "Enter an integer ";
	cin >> input;
	cout << "The double version of your input is " << endl;
	input_d = double(input);
	cout << input_d ;















	return 0;

}