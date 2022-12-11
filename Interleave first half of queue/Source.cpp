#include <iostream>
#include<queue>
using namespace std;


queue<int> interleave(queue<int> &q) {

	//getting mid to break into 2 queues , original queue and copy queue(having 1st half elements)
	int mid = q.size() / 2;

	queue<int> copy;

	//pushing first half to copy queue
	for (int count = 0; count < mid; ++count) {
		
		int value = q.front();
		q.pop();
		
		copy.push(value);


	}
	
	
	//pushing values back to original from copy in a interleafing logic
	//push copy>>pop front original>> push it back >>back to loop
	while (!copy.empty()) {

		//copy portion
		int value = copy.front();

		copy.pop();
		q.push(value);

		//original portion
		value = q.front();
		
		q.pop();
		q.push(value);
	}

	
	
	//returning required queue
	return q;
}






int main() {
	
	queue<int> q;

	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	interleave(q);

	while (!q.empty()) {
		cout << q.front() << endl;
		q.pop();
	}


	return 0;
}

