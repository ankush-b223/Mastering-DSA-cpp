#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;


class graph {

public:
	//graph is stored in this map

	//map< int -> nodes , list < of edges attached to the node >


	unordered_map<int, list<int> > adj;

	//method to add edge connection to nodes
	//established connection b/w u & v node 
	void addEdge(int u, int v, bool direction) {

		adj[u].push_back(v);

		if (!direction) {
			adj[v].push_back(u);
		}

	}

	//to print graph method
	void printList() {

		for (auto i : adj) {
			cout << i.first << "->";

			for (auto j : i.second) {
				cout << j << " , ";
			}

			cout << endl;

		}


	}




};






int main() {


	graph g;

	int n, m;

	//take no of nodes & edges

	cout << "Enter no of nodes" << endl;
	cin >> n;

	cout << "Enter no of edges " << endl;
	cin >> m;

	//run loop till no of edges so all conncetions are established 
	for (int count=0; count < m; ++count) {

		//taking each two nodes
		int u, v;

		cin >> u >> v;

		//making connection between them
		//assuming undirected graph so direction is false i.e 0
		g.addEdge(u, v, 0);

	}



	g.printList();


	return 0;
}