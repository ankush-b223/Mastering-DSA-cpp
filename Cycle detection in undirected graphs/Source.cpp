#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;


class graph {

public:

	unordered_map<int, list<int> > adjacencyList;

	void createConnection(int u, int v) {

		adjacencyList[u].push_back(v);
		adjacencyList[v].push_back(u);

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



//function defined using BFS technique
bool isCyclicBFS(int node, unordered_map<int, list<int> > adjacencyList, unordered_map<int, bool> visited, unordered_map<int, int> parent) {

	queue<int>q;
	//push source node
	q.push(node);
	//mark its visit
	visited[node] = true;

	//as source node has no parent make it -1
	parent[node] = -1;

	//till queue is empty
	while (!q.empty()) {
		//fetch front element
		int frontNode = q.front();
		//remove it
		q.pop();

		//traverse & process its adjacent nodes
		for (auto i : adjacencyList[frontNode]) {
			//if its already visited && it is not parent of fetched node (frontNode)
			//then cycle exists return true
			if (visited[i] && i != parent[frontNode]) {
				return true;
			}
			//if adjacent node doesnt exist process it 
			else if (!visited[i]) {
				q.push(i);
				visited[i] = true;
				parent[i] = frontNode;
			}

		}

	}

	//no cycle
	return false;

}


//function defined using DFS technique
bool isCyclicDFS(int node,int parent, unordered_map<int, list<int> > &adjacencyList, unordered_map<int, bool> &visited) {

	//mark node incoming as visited
	visited[node] = true;

	//traverse through adjacent nodes
	for (auto i : adjacencyList[node]) {
		//if its not visited
		if (!visited[i]) {
			//call recursive for it 
			//imp see parent is the node whose adjacentNodes are being accessed
			bool cycle = isCyclicDFS(i, node, adjacencyList, visited);

			//if call returns true cycle is there return true
			if (cycle) {
				return true;
			}

		}
		//if its visited && the adjacentNode is not equal to parent node
		//implies cycle is present so return true
		else if (i != parent) {
			return true;
		}
		
	}
	//no cycle return false;
	return false;

}









int main() {

	graph g;

	cout << "Enter no of nodes & edges " << endl;
	int n, e;

	cin >> n >> e;

	for (int i = 0; i < e; ++i) {
		cout << "Enter node data" << endl;

		int u, v;

		cin >> u >> v;

		g.createConnection(u, v);

	}

	//g.printList();

	//making required data structures
	unordered_map<int, int> parent;
	unordered_map<int, bool> visited;
	int flag = 0;
	bool ans;

	for (int count = 0; count < n; ++count) {

		if (!visited[count]) {
			ans = isCyclicDFS(count,-1, g.adjacencyList, visited);

			if (ans) {
				flag = 1;
			}
		}
		
	}

	
	if (flag == 0) {
		cout << "Cycle not present " << endl;
	}
	else {
		cout << "Cycle is present" << endl;
	}

	return 0;
}