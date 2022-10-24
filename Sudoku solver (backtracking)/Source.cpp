#include<iostream>
#include<vector>
using namespace std;




bool isSafe(vector<vector<int> >& board, int row, int column, int value) {

	//fetch size
	int n = board[0].size();

	//run loop to traverse the col , row & diagonals
	for (int count = 0; count < n; ++count) {

		//row check
		if (board[row][count] == value) {
			return false;
		}

		//column check
		if (board[count][column] == value) {
			return false;
		}

		//diagonal check
		if (board[ 3*(row/3) + count/3 ] [ 3*(column/3) + count%3 ] == value ){
			return false;
		}

	}
	//all cases false so value fdoesnt exist in sudoku so return true
	return true;

}





bool solve(vector<vector<int> >& board) {

	//fetch size
	int n = board[0].size();


	//traverse the matrix
	for (int row = 0; row < n; ++row) {
		for (int column = 0; column < n; ++column) {

			//if the curr iterated element is 0

			if (board[row][column] == 0) {

				// run loop for 1-9 values
				for (int value = 1; value <= 9; value++) {

					//for each value put in matrix and check it

					//if its safe put the value in sudoku
					if (isSafe(board, row, column, value)) {

						//putting value
						board[row][column] = value;

						//recursive call with value put in
						bool solutionCheck = solve(board);

						//if the recursive call fails at some point in the call tree
						if (solutionCheck) {
							//if no fails in call stack return true
							return true;
						}
						else { //failed recursion call
							//backtrack
							board[row][column] = 0;
						}

					}


				}
				//if all 1-9 values are put and its not getting match return false for ineligible solution
				return false;

			}

		}
	}

	
}




int main() {

	//givien initial soduko board
	vector<vector<int> > board;

	//solve fn call
	solve(board);


	return 0;
}