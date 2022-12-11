#include<iostream>
#include<stack>
#include<vector>
using namespace std;


//fn which would return the vector having the prev smallest bar of each height bar 
vector<int> prevSmallestElement(vector<int> heights) {

	vector<int> ans(heights.size());
	stack<int> stck;

	stck.push(-1);

	for (int count = 0; count < heights.size() ; ++count) {

		int element = heights[count];

		while (stck.top() != -1 && heights[stck.top()] >= element) {
			stck.pop();
		}

		ans[count] = stck.top();

		stck.push(count);


	}

	return ans;

}



//fn which would return the vector having the next smallest bar of each height bar
vector<int> nextSmallestElement(vector<int> heights) {

	vector<int> ans(heights.size());
	stack<int> stck;

	stck.push(-1);

	for (int count = heights.size() - 1; count >= 0; --count) {

		int element = heights[count];

		while ( stck.top() != -1 && heights[stck.top()] >= element) {
			stck.pop();
		}

		ans[count] = stck.top();

		stck.push(count);


	}

	return ans;
}

//largest histogram logic
int largestAreaRectangle(vector<int> &heights) {

	int area = INT_MIN;
	int size = heights.size();


	vector<int> prevVector(size);
	prevVector = prevSmallestElement(heights);

	vector<int> nextVector(size);
	nextVector = nextSmallestElement(heights);

	for (int count = 0; count < heights.size(); ++count) {

		int next = nextVector[count];
		int prev = prevVector[count];


		int length = heights[count];

		if (next == -1) {
			next = heights.size();
		}

		int width = next - prev - 1;

		int newArea = length * width;

		area = max(newArea, area);

	}

	return area;
}



int main() {

	//inputs
	int n=4;
	int m=4;

	vector<vector<int> > matrix = { {0 ,1, 1, 0} , {1, 1, 1, 1} , {1, 1, 1, 1} , {1, 1, 0, 0} };

	
	//initial area for first row of the matrix
	int area = largestAreaRectangle(matrix[0]);

	//starting from second row
	for (int count = 1; count < n; count++) {

		for (int test = 0; test < m; ++test) {

			//updating the rows by adding the values of it with the previous row

			//if the curr element is non zero
			if (matrix[count][test] != 0) {
				
				//update curr element as the sum of itself with element just above it ( in above row )
				matrix[count][test] = matrix[count][test] + matrix[count - 1][test];

			}
			//if curr element is 0
			//make sum and update as 0
			else {
				matrix[count][test] = 0;
			}

		}

		//get the newArea
		int newArea = largestAreaRectangle(matrix[count]);

		//store area as the max of exisiting area and newArea
		area = max(newArea, area);

	}

	//printning answer
	cout << area << endl;
	

	return 0;
}