#include<iostream>
#include<queue>
using namespace std;


class node {

public:

	int data;
	int row;
	int column;

	node(int val, int row, int column) {
		this->data = val;
		this->row = row;
		this->column = column;
	}

};


class compare {

public:

	bool operator()(node* A, node* B) {
		return A->data > B->data;
	}

};





int smallestRange(vector<vector<int> > karr, int size, int k) {

	//making minHeap
	priority_queue<node*, vector<node*>, compare > minheap;

	//initiating mini & maxi
	int mini = INT_MAX;
	int maxi = INT_MIN;

	//putting all the index0 elements of all k arrays to the minHeap
	for (int count = 0; count < k; ++count) {
		int element = karr[count][0];

		//on the way keeping track of the min element & max element in all k arrays
		mini = min(mini, element);
		maxi = max(maxi, element);

		minheap.push(new node(element, count, 0));
	}

	//start & end here have the maxi & mini values
	int start = mini;
	int end = maxi;

	//till minHeap is not empty
	while (!minheap.empty()) {

		//fetch the top
		node* top = minheap.top();
		//pop it
		minheap.pop();

		//update mini as top's data
		mini = top->data;
	
		//fetch othe data members of node fetched (i.e top)
		int row = top->row;
		int column = top->column;

		//with updated min check deffernce ,
		//if its smaller than diff of exisiting start & end ==>>> update start & end
		if (maxi - mini < end - start) {
			start = mini;
			end = maxi;
		}

		//move to next element in the array from where node was fetched
		//check index out of bound 
		if (column + 1 < karr[row].size()) {

			//update maxi checking max btw exisiting maxi & upcoming element in the arr[row[ ( from where node was fetched )
			maxi = max(maxi, karr[row][column + 1]);

			//push the next element to minHeap
			minheap.push(new node(karr[row][column + 1], row, column + 1));
		}
		else {
			//if any index out of bound /size 
			//break
			break;
		}



	}

	//return range
	return end - start - 1;

}





int main() {

	vector<vector<int> > input = { {2 ,4 ,5 }, { 5 ,6 ,7 } };
	int size=3;
	int k = input.size();

	int ans = smallestRange(input, size , k);

	cout << ans << endl;

	return 0;
}