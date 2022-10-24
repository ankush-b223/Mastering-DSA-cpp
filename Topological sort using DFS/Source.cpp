#include<iostream>
#include<unordered_map>
#include<stack>
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






void topologicalSort(int node, unordered_map<int, bool> &visited, stack<int> &stck, unordered_map<int, list<int> > &adjacencyList) {

	visited[node] = 1;

	for (auto i : adjacencyList[node]) {
		if (!visited[i]) {
			topologicalSort(i, visited, stck, adjacencyList);
		}
	}
	stck.push(node);
}







int main() {

	graph g;

	cout << "Enter no of nodes & edges " << endl;
	int n, e;
	cin >> n >> e;

	for (int count = 0; count < e; ++count) {

		cout << "Enter node data" << endl;
		int u, v;

		cin >> u >> v;

		g.createConnection(u, v);

	}

	unordered_map<int, bool> visited;
	stack<int> stck;

	for (int i = 0; i < n; ++i) {
		if (!visited[i]) {
			topologicalSort(i,visited,stck,g.adjacencyList);
		}
	}

	vector<int>ans;

	while (!stck.empty()) {
		ans.push_back(stck.top());
		stck.pop();
	}


	for (auto k : ans) {
		cout << k << " ";
	}

	cout << endl;

	return 0;
}