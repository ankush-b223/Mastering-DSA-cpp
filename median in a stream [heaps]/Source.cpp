#include<iostream>
#include<queue>
using namespace std;


//signum fn
int signum(int size1, int size2) {

	if (size1 == size2) {
		return 0;
	}
	else if (size1>size2) {
		return 1;
	}
	else {
		return -1;
	}

}

//main fn
void getMedian( int element , priority_queue<int> &maxHeap , priority_queue<int, vector<int>, greater<int> > &minHeap , int &median) {

	//check the size diff between heaps
	switch ( signum( maxHeap.size(), minHeap.size() ) ) {

		//maxHeap( smaller ) << median << minHeap ( bigger )  

		//size diff between both heap sizes cant be more than 1

		//size1 == size2

		//n - n
		case 0:
			//case 0 

			//if the element is bigger than curr median place it to minHeap
			if (element > median) {
				
				minHeap.push(element);

				//current size state is n -> median  -> n + 1 (just pushed to minHeap)

				//for n , n+1 
				median = minHeap.top();

			}
			else { //element < median

				// place it to maxHeap
				maxHeap.push(element);


				//curr state
				//n+1 -> n
				median = maxHeap.top();
			}

			break;


		//size1 > size2

		//n+1 -> n
		case 1:
			
			//element -> minHeap ( already in deficit so put)
			if (element > median) {
				minHeap.push(element);

				//curr state
				//n -> n
				//formula avg
				median = (minHeap.top() + maxHeap.top()) / 2;
			}
			else {//eleemnt < median

				//element -> maxHeap ( which is already +1 so putting will make the diff = 2 which not allowed
				//so before element insertion move one element from heap( having +1 i.e in this case minHeap ) to maxHeap ( heap with deficit )
				//then insert to heap from where record was moved (i.e minheap in this case )

				//moving record
				minHeap.push(maxHeap.top());
				maxHeap.pop();

				//pushing 
				maxHeap.push(element);

				// state logics
				// initial 
				//n + 1 -> n
				// after moving
				//n -> n+1
				// after element pushing (curr state)
				//n+1 -> n+1
				median = (minHeap.top() + maxHeap.top()) / 2;
			}

			break;

		//size1 < size2
		case -1:
			//case -1

			//vice versa logic of case 1 

			//n -> n+1

			if (element > median) {
				
				//moving
				maxHeap.push(minHeap.top());
				minHeap.pop();

				//n+1 -> n

				//pushing
				minHeap.push(element);

				//n+1 -> n+1

				median = (minHeap.top() + maxHeap.top()) / 2;
			}
			else {
				maxHeap.push(element);

				//n -> n 
				median = (minHeap.top() + maxHeap.top()) / 2;
			}

			break;

	}


}



int main() {

	//inputs
	vector<int> input = { 1, 2, 3 };
	//req data structures
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int> > minHeap;

	//size of the input array
	int size = input.size();

	//initializing median as 0
	int median = 0; 

	//vector ans to push all the simultanous answers
	vector<int> ans;

	//looping through the entire stream
	for (int count = 0; count < size; ++count) {

		//the current element from the stream
		int element = input[count];

		//get the median from the curr stream
		getMedian(element, maxHeap, minHeap, median);

		//push the curr stream's median to ans vector
		ans.push_back(median);

	}


	//printing vector
	for (auto i : ans) {
		cout << i << " ";
	}cout << endl;

	return 0;
}

