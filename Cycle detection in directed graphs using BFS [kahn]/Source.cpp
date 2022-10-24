#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;


class graph {


public:

	unordered_map<int, list<int> > adjacencyList;

	void createConnection(int u, int v) {

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

















int main() {

	graph g;

	cout << "Enter number of nodes & edges" << endl;
	int n, e;

	cin >> n >> e;

	for (int count = 0; count < e; ++count) {
		int u, v;
		cout << "Enter node data " << endl;
		cin >> u >> v;

		g.createConnection(u, v);
	}

	//making req data structurs
	unordered_map<int, bool> visited;
	//this map stores the indegree of each node
	unordered_map<int, int> indegree;

	//putting the indegree value of each node to the map
	for (auto i : g.adjacencyList) {
		for (auto j : i.second) {
			indegree[j]++;
		}
	}

	//make queue
	queue<int> q;

	//find nodes whose indegree is 0 and push them to queue
	//run from node 0 to n and check its indegree 
	// if 0 push
	for (int i = 0; i < n; ++i) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	//frequency of removal of nodes from q

	//if this is same as no of nodes in graph then 
	//no cycle otherwise cycle is present
	int freq=0;

	//till queue is empty
	while (!q.empty()) {
		//fetch front and pop it
		int front = q.front();
		q.pop();

		//increment counter
		freq++;

		//go to adjacent nodes of front 
		for (auto a : g.adjacencyList[front]) {
			//decrement its indegrees (as one node is already popped)
			indegree[a]--;
			//check for 0 indegree and push
			if (indegree[a] == 0) {
				q.push(a);
			}
		}

	}

	//checking condition and returning answer
	if (freq == n) {
		cout << "No cycle!" << endl;
	}
	else {
		cout << "Cycle is there" << endl;
	}

	return 0;
}

