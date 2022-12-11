#include <iostream>
#include <queue>
#include <stack>
using namespace std;



//fn def
//returns answer queue
queue<int> revByK(queue<int>q, int k) {

	//creating stack to reverse
	stack<int> s;

	//moving k elements to stack from queue
	for (int count = 0; count < k; ++count) {

		int value = q.front();

		q.pop();

		s.push(value);

	}

	//moving them back from stack to queue in a reversed manner
	while (!s.empty()) {
		int value = s.top();

		s.pop();

		q.push(value);
	}

	//size of non k elements on original queue
	int rem = q.size() - k;

	//popping non k elements from front and pushing them back to original queue positions
	for (int count = 0; count < rem; ++count) {

		int value = q.front();

		q.pop();
		q.push(value);


	}

	//returning queue
	return q;

}







//driver code
int main() {

	
	queue<int> q;

	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);

	int k = 3;

	queue<int> ans = revByK(q, k); \

	int n = ans.size();

	for (int count = 0; count < n; ++count) {
		cout << ans.front() << endl;
		ans.pop();
	}
	


	return 0;
}