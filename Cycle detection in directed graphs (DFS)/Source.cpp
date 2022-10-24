#include<iostream>
#include<unordered_map>
using namespace std;



class graph {

public:

	unordered_map<int, list<int> > adjacencyList;


	void createConnection(int u, int v) {

		//directed graph
		adjacencyList[u].push_back(v);
	}


	void printList() {
		for (auto i : adjacencyList) {
			cout << i.first << "-> ";

			for (auto j : i.second) {
				cout << j << " , ";
			}
			cout << endl;
		}

	}


};




//function def
bool isCyclicDFS(int node, unordered_map<int, bool>& visited, unordered_map<int, bool> &dfsVisited , unordered_map<int, list<int> > &adjacencyList) {

	//mark node's visit
	visited[node] = 1;
	//mark its call
	dfsVisited[node] = 1;

	//fetch adjacent nodes
	for (auto i : adjacencyList[node]) {
		//if not visited call recursive
		if (!visited[i]) {
			bool ans = isCyclicDFS(i, visited, dfsVisited, adjacencyList);

			if (ans) {
				return true;
			}
		}
		//here its already visited && its dfs call is also marked true
		//this is a case of cyclic condition in graph
		else if (dfsVisited[i]) {
			return true;
		}

	}

	//while going back remove from node call map (dfsVisited)
	dfsVisited[node] = 0;
	//if true isnt triggerred then no cycle exists
	return false;

}













//driver code
int main() {

	graph g;

	cout << "Enter no of nodes and edges " << endl;

	int n, e;

	cin >> n >> e;

	
	for (int count = 0; count < e; ++count) {

		cout << "Enter node data" << endl;
		int u, v;

		cin >> u >> v;

		g.createConnection(u, v);

	}


	//declaring req data structures
	unordered_map<int, bool> visited;
	//keeps track of recursive calls >> whether a particular node has already been called or not
	unordered_map<int, bool> dfsVisited;
	bool flag = false;
	
	for (int count=0; count < n; ++count) {

		if (!visited[count]) {
			bool ans = isCyclicDFS(count, visited, dfsVisited,g.adjacencyList);

			if (ans) {
				flag = 1;
			}
		}
	}

	if (flag) {
		cout << "Cycle is there " << endl;
	}
	else {
		cout << "Cycle is not there" << endl;
	}


	return 0;
}