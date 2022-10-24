#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class graph {

public:

	unordered_map<int, list<pair<int, int> > > adjacencyList;

	void createConnection(int u, int v, int weight) {

		adjacencyList[u].push_back(make_pair(v, weight));
		adjacencyList[v].push_back(make_pair(u, weight));


	}

	void printList() {

		for (auto i : adjacencyList) {
			cout << i.first << "-> ";
			for (auto j : i.second) {
				cout << "[ " << j.first << " , " << j.second << " ] ,, ";
			}
			cout << endl;
		}
	}

};






int main() {

	graph g;

	int nodes = 5;
	int edges = 14;

		g.createConnection(1 ,2, 2);
		g.createConnection(1 ,4, 6);
		g.createConnection(2 ,1, 2);
		g.createConnection(2 ,3, 3);
		g.createConnection(2 ,4, 8);
		g.createConnection(2 ,5, 5);
		g.createConnection(3 ,2, 3);
		g.createConnection(3 ,5, 7);
		g.createConnection(4 ,1, 6);
		g.createConnection(4 ,2, 8);
		g.createConnection(4 ,5, 9);
		g.createConnection(5 ,2, 5);
		g.createConnection(5 ,3, 7);
		g.createConnection(5 ,4, 9);


		//we need 3 data structures here i.e vectors

		//will store min distances from source for each node
		//we need the minimum spannning tree so vector to store min distances
		vector<int> key(nodes + 1);
		//is the node present in min spanning tree or not
		//all the nodes must be there in a mst
		vector<bool> mst(nodes + 1);
		//keeps track of parent node of all nodes
		//to fulfill the condition of mst i.e every node must be linked to each other
		vector<int> parent(nodes + 1);


		//initialise all the vectors
		//starting from node 1 since the input is from node 1 only

		for (int count = 1; count <= nodes; ++count) {
			//assuming all the distances to be infinity initially
			key[count] = INT_MAX;
			//no node in mst ininitally
			mst[count] = false;
			//every one parent we dont know now so null
			parent[count] = -1;
		}

		//get the source node
		int source = 1;
		//the min distance from source node to itself is ofc zero so put it in key vector
		key[source] = 0;

		//run loop
		for (int i = 1; i < nodes; ++i) {

			//initialte min with infinity
			int min = INT_MAX;
			//this U will track the node with least distance to source in the current iteration
			int u;

			//fetch out U from key vector
			for (int test = 1; test <= nodes; ++test) {
				//make sure the U fetched is not inserted to mst yet and hence is false
				if (mst[test] == 0 && key[test] < min) {
					u = test;
					min = key[test];
				}


			}

			//here we have the min dist to source node in the graph
			//assume putting it to the the MST by marking it true
			mst[u] = true;

			//fetch the adjacent nodes of U node
			for (auto adj : g.adjacencyList[u]) {

				//since the iterator will get us a pair having the adjacent node and weight of edge with U ( U-> adjNode )
				int adjNode = adj.first;
				int adjWt = adj.second;

				//if the node fetched is not in MST and 
				//the weight of the edge is lesser than the distance put in key vector for that particular adjacentNode then>>
				
				if (mst[adjNode] == false && adjWt < key[adjNode]) {
					//update the distance for that adjacent node with its weight
					key[adjNode] = adjWt;

					//when such an update is taking place also update the parent(i.e U node) the adjacentNode getting updated 
					parent[adjNode] = u;
				}

			}




		}




	//here the parent vector will store the nodes & edge data & min weights present in the mst formed by the graph


	return 0;
}
