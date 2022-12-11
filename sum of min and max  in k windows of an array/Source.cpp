#include <iostream>
#include<queue>
using namespace std;

int solve(int *arr, int size, int k) {

	deque<int> maxi;
	deque<int> mini;

	int answer = 0; 

	for (int count = 0; count < k; ++count) {

		while (!maxi.empty() && arr[maxi.back()] <= arr[count]) {

			maxi.pop_back();

		}


		while (!mini.empty() && arr[mini.back()] >= arr[count]) {
			mini.pop_back();
		}

		maxi.push_back(count);
		mini.push_back(count);

	}

	answer += arr[maxi.front()] + arr[mini.front()];
	//process remaining windows 

	for (int count = k; count < size; count++) {

		//removal

		while (!maxi.empty() && count - maxi.front() >= k) {
			maxi.pop_front();
			
		}
		
		while (!mini.empty() && count - mini.front() >= k) { 
			mini.pop_front();
			
		}

		//addition

		while (!maxi.empty() && arr[maxi.back()] <= arr[count]) {

			maxi.pop_back();

		}


		while (!mini.empty() && arr[mini.back()] >= arr[count]) {
			mini.pop_back();
		}

		maxi.push_back(count);
		mini.push_back(count);


		//answer update

		answer += arr[maxi.front()] + arr[mini.front()];
		

	}

	return answer;
}



int main() {

	int arr[100] = { 2, 4 ,7, 3, 8, 1 };
	int k = 4;
	int size = 6;

	cout << solve(arr,size,k) <<  endl;


	return 0;
}