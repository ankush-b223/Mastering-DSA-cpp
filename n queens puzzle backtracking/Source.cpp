#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;



//optimisation
//instead for traversing entire row, col & diagonals to search for other possible attacking queens

//make a hashmap entry for the particular row/col/diagonal while inserting a queen

//while checking for safe queen placement ak the corresponding hashmap whether in that row/col/diagonal other queens exist -> op will take  [ o(1) ] 
//instead of o(n) required to traverse


void addSolution(vector<vector<int> >& board, vector<vector<int> >& answer, int size) {
    //the board here has a possible solution

    //temp vector to store current possible solution values
	vector<int> temp;

    //traversing entire matrix
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			//pushing solution values
            temp.push_back(board[i][j]);
		}
	}

    //temp has curr possible sol values

    //push temp to final answer

	answer.push_back(temp);

}




bool isSafe(int column, int row , vector<vector<int>  >& board, int size) {

    int x = row;
    int y = column;

    //check whether row is clear of other placed queens or not
    while (y >= 0) {
        if (board[y][x] == 1) {
            return false;
        }
        y--;
    }
    //cout << "Row op is safe " << endl;

    //check diagonals
    //dry run matrices to understand the conditions




    //for upper diagonal

    //reinitialising the values
    x = row;
    y = column;

    while (x >= 0 && y >= 0) {
        if (board[x][y] == 1) {
            return false;
        }
        x--;
        y--;
    }

    cout << "Up diagonal op is safe " << endl;

    //for lower diagonal
    x = row;
    y = column;

    while (x < size && y >= 0) {

        if (board[x][y] == 1) {
            return false;
        }

        x++;
        y--;
    }

    cout << "down diagonal op is safe " << endl;

    //if all ops are safe so true as the quuen can be placed here
    return true;

}


void solve(int column, vector<vector<int> >& board, vector<vector<int> >& answer, int size) {

    //base case

    //if the column is equal to size => matrix is ready with a possible solution 
	if (column == size) {

        //here the board contains a possible solution so push it to answer

		addSolution(board, answer, size);

        //return back
		return;
	}

    //traverse the row for the given column
	for (int row = 0; row < size; ++row) {

        //is it safe to put the queen in the current iteration row,col coordinate
		if (isSafe(column, row, board, size)) {
            
            //so this particular coordiante is safe so put the queen here
			board[row][column] = 1;

            //recursive call for next column
			solve(column + 1, board, answer, size);

            //while returning for a fresh solution remove the queens you have placed to get the previous solution

            //backtracking
			board[row][column] = 0;

		}


	}





}





int main() {

    //input no of rows
	int size = 4;

    //required ds
    //the board chess
	vector<vector<int> > board(size, vector<int>(size, 0));
	
    //answer returnrer
	vector<vector<int> > answer;

    //first call for column 0
	solve(0, board, answer, size);

    //printing answer
	cout << answer.size() << endl;







	return 0;
}