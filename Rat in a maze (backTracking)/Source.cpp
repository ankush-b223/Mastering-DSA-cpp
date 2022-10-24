#include<iostream>
#include<vector>
using namespace std;


bool isSafe(int newX, int newY, vector < vector<int> > inputMatrix, vector<vector<bool> >& visited, int size) {

    //conditions if the move is premitted or not 

    // if the coordinates are in the matrix ,, inputmatrix allows the move , its not yet visited
	if ((newX < size && newX >= 0) && (newY < size && newY >= 0) && (inputMatrix[newX][newY] == 1) && (visited[newX][newY] != 1)) {
		return true;
	}

	else {
		return false;
	}
}




void solve(int x, int y, vector < vector<int> > inputMatrix, vector<string> &answer, string &result, vector<vector<bool> > &visited , int size) {

    //base case
    if (x == size - 1 && y == size - 1) {
        answer.push_back(result);
        return;
    }

    //mark visit
    visited[x][y] = 1;
    //down ..
    if (isSafe(x + 1, y, inputMatrix, visited, size)) {

        //result.push_back('D');
        solve(x + 1, y, inputMatrix, answer, result + 'D', visited, size);

    }


    //left..
    if (isSafe(x, y - 1, inputMatrix, visited, size)) {

        //result.push_back('L');


        solve(x, y - 1, inputMatrix, answer, result + 'L', visited, size);

    }


    //right..
    if (isSafe(x, y + 1, inputMatrix, visited, size)) {

        //result.push_back('R');


        solve(x, y + 1, inputMatrix, answer, result + 'R', visited, size);

    }


    //up..
    if (isSafe(x - 1, y, inputMatrix, visited, size)) {

        //result.push_back('U');

        solve(x - 1, y, inputMatrix, answer, result + 'U', visited, size);


    }
    //while coming back demark visits (for further paths)
    visited[x][y] = 0;





}




int main() {

	vector < vector<int> > inputMatrix = { {1,0,0,0} , {1,1,0,0} , {1,1,0,0} , {0,1,1,1}  };

	int size = 4;

    //answer returner
	vector<string> answer;
    //tmep storer
	string result = "";

    //visited ds
	vector<vector<bool> > visited(size, vector<bool>(size, 0) );

    if (inputMatrix[0][0] == 0) {
        return ;
    }

    //first call
	solve(0, 0, inputMatrix, answer, result , visited , size);


    //printing
	for (auto i : answer) {
		cout << i << " ";
	}cout << endl;

	return 0;
}