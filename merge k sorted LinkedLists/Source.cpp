#include<iostream>
#include<queue>
using namespace std;

//LL node def
class node {

public:

	int data;
	node* next;

	node(int val) {

		this->data = val;
		this->next = NULL;
	}


};





//since storing node* objects in minheap so own defined comparator is req
class compare {
public:

	bool operator()(node* A, node* B) {
		return A->data > B->data;
	}


};


//main  fn
node* mergeKLists(vector<node*>& listArray) {

	//creating a minHeap having node objects
	priority_queue<node*, vector<node*>, compare > minHeap;

	//fetching the no of LL (K) from  the vector of heads
	int k = listArray.size();

	//if no heads present return null
	if (k == 0) {
		return NULL;
	}

	//push all the k heads to the minheap

	//pushing all k head to min heap
	for (int count = 0; count < k; ++count) {

		//if the head is not null then push
		if (listArray[count] != NULL) {
			minHeap.push(listArray[count]);
		}
	}

	//here the minHeap hass all the k heads

	//initiate the head & tail of the merged LL to be formed
	node* head = NULL;
	node* tail = NULL;

	//till the mineheap has elements
	while (minHeap.size() > 0) {

		//fetch the top element
		node* top = minHeap.top();
		//remove it form the heap
		minHeap.pop();

		//moving to the next node in particular k LL from where node has been popped

		//if the fetched node's next is not empty ,, i.e the LL from where node is going to be merged is not empty
		if (top->next != NULL) {
			//push to min heap
			minHeap.push(top->next);
		}
		
		//pushing top node fetched to the main merged LL

		//if the merged LL is empty => first element isnertion
		if (head == NULL) {
			//initiate both head & tail
			//to top which is the node fetched
			head = tail = top;
		}
		//elements already exist in the mergedLL
		else {
			//attach fetched node to the tail
			tail->next = top;
			//update tail
			tail = tail->next;
		}

		//all the ndoes will get inserted in a sorted manner as the minHeap top will have the most min element as its top 

	}

	//return head of mergedLL
	return head;


}




int main() {
	

	//works perfect //check code studio



	return 0;
}