#include<iostream>
#include<queue>
using namespace std;

//to traverse through the vectors simultaneously >> this class is created to represent an element 
//it will hold the data , the array's row & column to determin which element from which array
class node {

public:

	int data;
	int row;
	int column;

	//constructor
	node(int data, int row, int  column) {
		this->data = data;
		this->row = row;
		this->column = column;
 	}


};

//comparator
//since in the heap node* objects will be put in so own comparator is req
class compare {

public:

	bool operator()(node* A, node* B) {
		return A->data > B->data;
	}

};



vector<int> mergekArrays(vector<vector<int> >& arr, int k) {

	//creating minHeap which will contains elements in the form nodes
	priority_queue<node*, vector<node*>, compare > minHeap;
	
	//the arrays given are sorted so

	//put in all the index[0] eleemnts of all k arrays to the heap
	for (int count = 0; count < k; ++count) {
		node* toPut = new node(arr[count][0], count, 0);
		minHeap.push(toPut);

	}

	//now the  heap contains all the index 0 elements of k arrays 

	//answer returning vector
	vector<int> ans;

	//till the heap is not empty
	while (minHeap.size() > 0) {

		//fetch out the top element(node)  => (which is the most min in the heap) 
		node* temp = minHeap.top();
		//pop it
		minHeap.pop();

		//fetch the eleemnt fetched data memebers
		int data = temp->data;
		int row = temp->row;
		int column = temp->column;

		//push the data to vector( as it is the smallest ) 
		ans.push_back(data);

		//check if the array from where element was fetched (determined using row data member ) 
		//has a next element ( determined by column)
		//if col +1 is in the particular array's size then the next element exists

		if (column+1 < arr[row].size()) {
			//make a node for the next element in that particular node
			//see col+1 in args
			node* nextIndex = new node(arr[row][column + 1], row, column + 1);

			//push the node next created to the heap
			minHeap.push(nextIndex);
		}

		//repeat
		
	}

	//return the ans vector
	return ans;

}






int main() {

	//inputs

	vector<vector<int> > kArrays = { { 3 ,5, 9 }, {1 ,2, 3, 8} };

	//no of arrays in the 2darray 
	int k = 2;

	//ans fetching
	vector<int> ans = mergekArrays( kArrays ,  k);

	//printing answer
	for (auto i : ans) {
		cout << i << " ";
	}


	return 0;
}