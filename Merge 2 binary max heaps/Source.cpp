#include<iostream>
#include<vector>
#include<queue>
using namespace std;





void heapify(vector<int>& arr, int size, int index) {

	int largest = index;

	//0 based indexing
	int left = 2 * index+1;
	int right = 2 * index + 2;

	if (left < size && arr[left] > arr[largest]) {
		largest = left;
	}
	if (right < size && arr[right]> arr[largest]) {
		largest = right;
	}

	if (largest != index) {
		swap(arr[largest], arr[index]);
		heapify(arr, size, largest);
	}

}





vector<int> merge2Heaps(vector<int> &heap1, vector<int> &heap2, int size1, int size2) {

	//vector merged
	vector<int> merged;

	//merge 2 arrays in any random order
	//array1
	for (int i = 0; i < size1; i++) {
		merged.push_back(heap1[i]);
	}

	//array 2
	for (int i = 0; i < size2; i++) {
		merged.push_back(heap2[i]);
	}

	//merged array is prepared
	int size = merged.size();

	//subject to heapify fn
	//runnning loop from half since the rest are leaf nodes which are already heaps in itself
	for (int i = size /2 -1; i >= 0; i--) {
		heapify(merged, size, i);
	}

	//return merged vector which is a max heap
	return merged;

}



int main() {

	//given are two max heaps as vectors 
	vector<int> heap1 = {};
	vector<int> heap2 = {};

	//getting their sizes
	int size1 = heap1.size();
	int size2 = heap2.size();

	//ans fetching from fn call
	vector<int> ans = merge2Heaps(heap1, heap2 , size1, size2);


	//printing ans
	for (auto i : ans) {
		cout << i << " ";
	}
	cout << endl;

	return 0;

}