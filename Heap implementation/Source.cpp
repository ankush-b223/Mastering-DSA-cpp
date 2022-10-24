#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class heap {

	//heap is basically a Complete binary tree following the heapify logic

	//max-heap & min-heap ( wrt to parent )

	//data members in a heap
public:

	//MAX-HEAP

	//the arr is used to represent the heap
	int arr[100];
	//size of heap
	int size=0;


	//assuming 1 index-based heap

	//here arr[0] is assumed to be null

	//function to insert a value ot the heap 
	void insert(int value) {
		//inserting an element so increment the size
		size += 1;

		//the index where the element is to be inserted is pointed by size (last element of the arr)
		int index = size;

		//put the element coming in at the end of thee arr
		arr[index] = value;

		//placing the element placed at end at its correct index acc to heapify logic

		//till the index is greater than 1
		while (index > 1) {

			//the parent of a node in  a heap is represented by the i/2 index

			//if the the parent of new element is smaller than new element
			//swap

			//update the index as it should track the curr position of the new element

			if (arr[index / 2] < arr[index]) {
				swap(arr[index / 2], arr[index]);
				//updating the index
				index = index / 2;
			}
			//if in correct position return as heapify logic is established
			else {
				return;
			}

		}
	}




	//this function deletes the root of a heap always
	//deleting from a heap mean to delete the root of the heap
	void deleteHeap() {

		//underflow
		if (size == 0) {
			cout << "Underflow" << endl;
		}

		//root is in 1 index ( 1 based indexing )

		//put the last element as the root 
		arr[1] = arr[size];

		//reduce the size
		size--;

		//get tracker of last element which has been put in as root currently
		int i = 1;
		
		//now just place the changed element to its correct position acc to the heapify logic

		//till i is in bound of the updated size
		while (i < size) {

			//fetch the left & right childs of the i element

			//formula based on 1 based index

			//for 0 based ( left-> 2*i +1 , right -> 2*i +2)

			//1 based so
			int leftChild = 2 * i;
			int rightChild = 2 * i + 1;


			//if left index is inbound of range and is smaller than child so swap
			if (leftChild<size && arr[leftChild] > arr[i]) {
				swap(arr[leftChild], arr[i]);
				i = leftChild;
			}
			else if (rightChild <size && arr[rightChild] > arr[i]) {
				swap(arr[rightChild], arr[i]);
				i = rightChild;
			}
			//in correct position so return
			else {
				return;
			}
		}

	}





	//prints heap array
	void print() {
		for (int i = 1; i <= size; ++i) {
			cout << arr[i] << ' ';
		}
		cout << endl;
	}

};

//takes the index(count) to its correct heap place in the array 
void heapify(int arr[], int size , int count) {

		int largest = count;

		int lChild = 2 * count;
		int rChild = 2 * count + 1;


		if (lChild <= size && arr[largest] < arr[lChild]) {
			largest = lChild;
		}
		if (rChild <= size && arr[largest] < arr[rChild]) {
			largest = rChild;
		}


		if (largest != count) {
			swap(arr[largest], arr[count]);
			heapify(arr, size, largest);
		}

	

}



void heapSort(int arr[], int size) {

	int n = size;

	while (n > 1) {

		swap(arr[1], arr[n]);
		n--;

		heapify(arr, n, 1);
	}

}



int main() {

	heap h;
	h.insert(50);
	h.insert(55);
	h.insert(53);
	h.insert(52);
	h.insert(54);
	//h.print();


	h.deleteHeap();
	//h.print();

	int array[6] = { -1, 1,2,3,4,5 };

	int size = 5;

	//ignoring the leaf nodes int the loop since they are already heaps 
	//the loop moves in reverse direction 
	for (int i = size / 2; i > 0; i--) {
		heapify(array, size, i);
	}


	cout << "printing " << endl;
	for (int i = 1; i <= size; ++i) {
		cout << array[i] << " ";
	}
	cout << endl;



	heapSort(array, size);
	cout << "printing " << endl;
	for (int i = 1; i <= size; ++i) {
		cout << array[i] << " ";
	}
	cout << endl;





	//heaps stl using priority queue

	//this is an maxHeap;
	priority_queue<int> maxHp;

	//this is a min heap
	priority_queue<int, vector<int>, greater<int> > minHp;

	return 0;
}



