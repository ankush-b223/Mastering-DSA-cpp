#include<iostream>
#include<stack>
#include<vector>
using namespace std;

//next vector preparation >> it will contain the indexes of the next bar smaller than curr bar
vector<int> nextSmallerElement(vector<int>& bars) {

	//create ans vector
	vector<int> ans(bars.size());
	//stck req
	stack<int> stck;

	//push -1 as the next of last element
	stck.push(-1);

	//loop from the end of bars vector
	for (int count = bars.size() - 1; count >= 0; --count) {

		//fetch curr element
		int element = bars[count];

		//till the next index is smaller 
		while (stck.top() != -1 && bars[stck.top()] >= element) {
			stck.pop();
		}

		//here the index is stored
		ans[count] = stck.top();

		//push the index
		stck.push(count);

	}

	//return
	return ans;
}

vector<int> nextBiggerElement(vector<int>& bars) {

	//same logic as above
	vector<int> ans(bars.size());

	stack<int> stck;

	stck.push(-1);

	//loop from front
	for (int count = 0; count < bars.size(); count++) {
		int element = bars[count];

		while(stck.top() != -1 && bars[stck.top()] >= element) {
			stck.pop();
		}

		ans[count] = stck.top();
		
		//push index
		stck.push(count);

	}


	return ans;
}



int main() {

	vector<int> bars = { 2,1,5,6,2,3 };


	//fetch the next and prev indexes of all the bar heights
	vector<int> next = nextSmallerElement(bars);

	vector<int> prev = nextBiggerElement(bars);

	//fix area
	int area = INT_MIN;

	//loop from front
	for (int count = 0; count < bars.size(); ++count) {

		//the length wil;l bew the bar itself
		int length = bars[count];

		//if the end bar is in curr iteration
		if (next[count] == -1) {
			//fix -1 to -> n 
			next[count] = bars.size();
		}


		//width ,, next index - prev index - 1
		int width = next[count] - prev[count] - 1;

		//make newArea with curr iteration length & width
		int newArea = length * width;

		//area will be the max of area & newArea
		area = max(area, newArea);

		
	}

	//print answer
	cout << area << endl;


	return 0;
}