#include<iostream>
#include<queue>
using namespace std;


struct petrolPump {
public:
	int petrol;
	int distance;

};


//queue approach
int circularTour1(petrolPump p[] , int size) {

	
	int front = 0;
	int rear = 0;
	int balance=0;
	int iterate=0;


	for (int count = 0; count < size; ++count) {


		balance += p[iterate].petrol;

		if (balance >= p[iterate].distance) {

			if (rear == size - 1) {
				rear = 0;
			}
			else {
				rear++;
			}

			balance = balance - p[iterate].distance;

			if (front == rear) {
				return front;
			}
			
			++iterate;
		}
		else {
			front = rear + 1;
			rear = front;
			iterate = front;
			balance = 0;
			count = -1;
		}

		
	}

	return -1;

	

}

//optimised approach
int circularTour2(petrolPump p[], int size) {

	int start = 0;
	int balance = 0;
	int deficit = 0;

	for (int count = 0; count < size; ++count) {

		balance += p[count].petrol - p[count].distance;

		if (balance < 0) {
			deficit += balance;
			start = count + 1;
			balance = 0;
		}

	}

	//if the balance petrol is sufficient to travel the earlier deficit petrol then starting position can make a circular tour
	if (balance + deficit>=0) {
		return start;
	}
	else {
		return -1;
	}
}


int main() {

	//declaring structure petrol pump for input
    const int n =4;
    petrolPump p[n];

	p[0].petrol = 4;
	p[0].distance = 6;

	p[1].petrol = 6;
	p[1].distance = 5;

	p[2].petrol = 7;
	p[2].distance = 3;

	p[3].petrol = 4;
	p[3].distance = 5;
    
	int ans = circularTour1(p, n);
	cout << ans << endl;


	return 0;
}