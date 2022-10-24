#include<iostream>
#include<unordered_map>
#include<stack>
#include<vector>
using namespace std;


class graph {


public:

	unordered_map<int, list<int> > adjList;

	void createConnection(int u, int v) {

		adjList[u].push_back(v);

	}

};


void dfs(int node, unordered_map<int, bool>& visited, stack<int>& stck, unordered_map<int, list<int> > & adjList) {
	
	visited[node] = 1;

	for (auto adjNode : adjList[node]) {

		if (!visited[adjNode]) {
			dfs(adjNode, visited, stck, adjList);
		}

	}

	stck.push(node);
}




void revDfs(int node, unordered_map<int, bool>& visited, unordered_map<int, list<int> > &adjList) {

	visited[node] = 1;

	for (auto adjNode : adjList[node]) {

		if (!visited[adjNode]) {
			revDfs(adjNode, visited, adjList);
		}

	}
}



int main() {

	graph g;

	int nodes = 5;


	g.createConnection(0,1);
	g.createConnection(1,2);
	g.createConnection(1,4);
	g.createConnection(2,3);
	g.createConnection(3,2);
	g.createConnection(4,0);


	//creating req data structures

	//for topo sort
	unordered_map<int, bool> visited;
	stack<int> stck;

	//performing topo sort
	for (int node = 0; node < nodes; ++node) {
		if (!visited[node]) {
			dfs(node, visited, stck, g.adjList);
		}
	}

	//here i have top sort ready in stck

	//create another transpose graph
	//a graph with just opp directions as original graph
	unordered_map<int, list<int> > transposeList;

	//we are transposing the graph coz the stck will return as element in reverse order so applying in reverse graph
	
	//creating it transpose graph
	for (int i = 0; i < nodes; ++i) {
		//also marking all nodes vsit as false to use again
		visited[i] = 0;

		//reverse linking
		for (auto j : g.adjList[i]) {
			transposeList[j].push_back(i);
		}

	}
	//we have to return the number of SCC components so count to track it
	int count = 0;

	//performing dfs from the order in stack
	while (!stck.empty()) {

		//fetch top
		int top = stck.top();
		//pop it
		stck.pop();
		
		//if its not yet visited
		if (!visited[top]) {
			++count;
			//call for dfs

			//one such call will return when its find one SCC component
			revDfs(top, visited, transposeList);
		
		}
	}

	//returning answer
	cout << count<<endl;
	return 0;
}