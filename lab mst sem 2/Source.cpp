#include <iostream>
using namespace std;

class rectangle {
public:
	//data members of the class
	int length;
	int breadth;

	//parameterized constructor 
	rectangle(int l , int b) {
		this->length = l;
		this->breadth = b;
	}

	//memeber function
	int Area() {
		return length * breadth;
	}
};

int main() {

	//Instantiating objects
	rectangle rec1(4,5);
	rectangle rec2(5, 8);

	//printing out the areas
	cout << rec1.Area() << endl;
	cout << rec2.Area() << endl;

	return 0;
}