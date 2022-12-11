#include <iostream>
#include <stack>
#include <queue>
using namespace std;

//reversal fn def
//fn shpould return queue
queue<int> rev(queue<int>q, int size) {

	//declaring stack
	stack<int> s;

	//psuhing queue values to stack
	while (!q.empty()) {
		int element = q.front();

		q.pop();

		s.push(element);
	}

	//pushing stack values back to queue ( stack reverses )
	while (!s.empty()) {
		
		int value = s.top();
		s.pop();

		q.push(value);
	}

	//returning reversed queue
	return q;
}

//driver code
int main() {

	//creating i/p queue
	queue<int> q;

	//pushing values to i/p queue
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);


	//declaring size
	int size = 4;

	//calling reversal fn and storing the returning queue in a answer queue
	queue<int> ans = rev(q, size);

	
	//printing out queue
	while (!ans.empty()) {
		
		cout << ans.front() << endl;
		ans.pop();
	}

	return 0;
}
