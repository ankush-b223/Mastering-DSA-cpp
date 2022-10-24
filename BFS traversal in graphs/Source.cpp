#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;


//we create the graph using graph class
class graph {

public:

	//assuming the adjacency list to be a data member of the graph
	unordered_map<int, list<int> > adjacencyList;

	//this method creates the graph connections
	void createGraph(int node1, int node2) {

		adjacencyList[node1].push_back(node2);
		adjacencyList[node2].push_back(node1);

	}

	//this method prints the adjacecny list
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

//breadth first search function
//has adjList , the node , visited map , and returning ans vector to store the data
void bfs(unordered_map<int, list<int> > &adjacencyList, int node, unordered_map<int,bool> &visited,vector<int> &ans) {

	//creation of queue
	queue<int>q;

	//push the node data coming in
	q.push(node);
	//mark its visit as true
	visited[node] = 1;

	//till queue is empty
	while (!q.empty()) {
		//fetch front node
		int frontNode = q.front();
		//remove it from queue
		q.pop();

		//push it to answer vector
		ans.push_back(frontNode);

		//access the neighbouring nodes through adjacency list
		for (auto i : adjacencyList[node]) {
			if (!visited[i]) {
				//if the neighbouring node isnt visited then psuh to queue and marks its visit
				q.push(i);
				visited[i] = 1;
			}
		}

	}

	//ans is passed by refernce so its stored


}




int main() {

	//fetching graph data
	graph g;

	int n, e;

	cout << "enter no of nodes " << endl;

	cin >> n;

	cout << "Enter no of edges " << endl;

	cin >> e;
	//creating graph
	for (int count = 0; count < e; ++count) {

		int u, v;
		cout << "Enter node datas" << endl;
		cin >> u >> v;

		g.createGraph(u, v);
	
	}



	//making required data structures
	unordered_map<int, bool> visited;
	vector<int> ans;

	//g.printList();

	//this loop is to check for disconnected graphs too
	for (int i = 0; i < n;++i) {

		if (!visited[i]) {
			bfs(g.adjacencyList, i, visited,ans);
		}

	}
	
	//prints answer
	for (auto loop : ans) {
		cout << loop << " ";
	}

	return 0;
}