#include <iostream>
#include<queue>
using namespace std;


vector<int> solve(int arr[], int k,int size) {

	vector<int> answer;
	deque<int> q;

	//solving first k window
	for (int count = 0; count < k; ++count) {
		if (arr[count] < 0) {
			//store index in queue
			q.push_back(count);
		}
	}

	//push answer of first k window to answer vector
	if (!q.empty()) {
		answer.push_back(arr[q.front()]);
	}
	else {
		answer.push_back(0);
	}



	//for remaining windows
	for (int count = k; count < size; ++count) {

		//removal from window check args
		if (!q.empty() && ( count - q.front()) >= k) {

			q.pop_front();

		}

		//addition to window
		if (arr[count] < 0) {
			q.push_back(count);
		}

		//update answer vector
		if (!q.empty()) {
			answer.push_back(arr[q.front()]);
		}
		//if no negative integer in that window push 0
		else {
			answer.push_back(0);
		}

	}

	//return answer vector
	return answer;
}





int main() {
	
	//{-8, 2, 3, -6, 10}
	//K = 2

	queue<int> q;

	int array[100] = { -8, 2, 3, -6, 10 };

	int size = 5;
	int k = 2;

	vector<int> answer = solve(array, k, size);

	for (int count = 0; count < answer.size(); ++count) {
		cout << answer[count] << endl;
	}


	return 0;
}