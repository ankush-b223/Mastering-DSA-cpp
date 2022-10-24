#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


class graph {

public:

	unordered_map<int, list<pair<int,int> > > adjList;

	void createConnection(int u, int v , int wt) {
		
		adjList[u].push_back({ v,wt });

	}

};






//run loop for n-1 times to update the distances

//run for another time outside to check for negative cycle



int main() {

	int nodes = 5;

	graph g;

	g.createConnection(0, 1, 5);
	g.createConnection(1,2,-4);
	g.createConnection(0,2,2);


	vector<int> distance(nodes , INT_MAX);

	int source = 0;

	distance[source] = 0;



	for (int i = 0; i < nodes - 1; ++i) {

		for (auto adjNode : g.adjList[i]) {

			int adjN = adjNode.first;
			int weight = adjNode.second;

			if (distance[i] + weight < distance[adjN]) {
				distance[adjN] = distance[i] + weight;

			}

		}

	}

	int dest = 2;


	cout << distance[dest];




	//check gfg & codestudio for proper code 


	return 0; 
}