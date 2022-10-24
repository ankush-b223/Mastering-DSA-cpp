#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


class graph {

public:

	unordered_map<int, list<int> > adjacencyList;

	void createConnection(int u, int v) {

		adjacencyList[u].push_back(v);
		adjacencyList[v].push_back(u);

	}



};


void dfs(int node, int parent, int& timer, vector<int>& discoverytTime, vector<int>& lowestTime, unordered_map<int, bool>& visited , unordered_map<int, list<int> > &adjacencyList, vector<vector<int> > &result) {

	//mark the node's visit
	visited[node] = true;

	//allot both the times as the timer value initially
	discoverytTime[node] = lowestTime[node] = timer++;

	//fetch all the adjacent nodes
	for (auto adjNode : adjacencyList[node]) {

		//if the adjacent node passed is the parent of the node ignore this adjacentNode iteration & continue to next adjacentNode
		if (adjNode == parent) {
			continue;
		}

		//if the adjacentNode is not visited yet
		if (!visited[adjNode]) {

			//call dfs
			dfs(adjNode, node, timer, discoverytTime, lowestTime, visited, adjacencyList, result);


			lowestTime[node] = min(lowestTime[node], lowestTime[adjNode]);


			if (lowestTime[adjNode] > discoverytTime[node]) {

				vector<int> ans(15);
				ans.push_back(node);
				ans.push_back(adjNode);
				

				result.push_back(ans);

			}




		}
		else {
			//back edge case 

			lowestTime[node] = min(lowestTime[node], discoverytTime[adjNode]);
		}

	}




}











int main() {

	//creating graph
	graph g;


	//no of nodes
	int nodes = 5;

	g.createConnection(5, 4);
	g.createConnection(0, 1);
	g.createConnection(3, 1);
	g.createConnection(1, 2);
	g.createConnection(3, 4);
	g.createConnection(3, 3);
	g.createConnection(0, 1);
	g.createConnection(1, 2);
	g.createConnection(2, 0);


	//the timer 
	int timer = 0;

	//the req data structures

	//tracks timer at discovery of node
	vector<int> discoveryTime(nodes+1);

	//tracks lowestTime to reach node
	vector<int>LowestTime(nodes+1);
	//visited map
	unordered_map<int, bool> visited;

	//the parent tacker of a particular node
	int parent = -1;

	//ans returning variable
	vector<vector<int> > result;

	//dfs call for all components in a graph
	for (int i = 0; i < nodes; i++) {
		if (!visited[i]) {
			dfs(i , parent , timer , discoveryTime,LowestTime,visited ,g.adjacencyList,result);
		}
	}


	cout << "Result ready" << endl;


	/* 
	for (int count = 0; count < nodes; ++count) {
		for (int test = 0; test < nodes; ++test) {
			cout << result[count][test] << " ";
		}
		cout << endl;
	}
	*/

	return 0;
}