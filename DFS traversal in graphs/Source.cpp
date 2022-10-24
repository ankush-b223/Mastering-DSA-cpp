#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


class graph {


public:

	unordered_map<int, list<int> > adjacentList;



	void createConnection(int u, int v) {

		//assuming undirected

		adjacentList[u].push_back(v);
		adjacentList[v].push_back(u);

	}


	void printAdjList() {

		for (auto i : adjacentList) {
			
			cout << i.first<< "-> ";

			for (auto j : i.second) {
				cout << j << " , ";
			}

			cout << endl;
		}

	}


};





void dfs(unordered_map<int, list<int> >& adjacencyList, int node, unordered_map<int, bool>& visited, vector<int>& component) {

	component.push_back(node);
	visited[node] = true;

	for (auto i : adjacencyList[node]) {

		if (!visited[i]) {
			dfs(adjacencyList, i, visited, component);
		}
	}


}












int main() {

	graph g;

	int n, e;

	cout << "Enter no of nodes " << endl;
	cin >> n;

	cout << "Enter no of edges " << endl;
	cin >> e;

	for(int count =0;count<e;++count){

		int u, v;

		cout << "enter node data " << endl;

		cin >> u >> v;

		g.createConnection(u, v);
	}

	//g.printAdjList();

	unordered_map<int, bool> visited;

	vector<int> component;
	vector<int> ans;

	for (int i = 0; i < n; ++i) {
		if (!visited[i]) {
			dfs(g.adjacentList, i,visited,component);

		}

		

	}
	
	for (auto j : component) {
		//cout << "DFS traversal is " << endl;
		cout << j << " ";

	}


	return 0;
}