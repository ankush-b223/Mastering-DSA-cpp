#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
using namespace std;

class graph {

public:

	unordered_map<int, list<int> > adjacencyList;

	void createConnection(int u, int  v) {

		adjacencyList[u].push_back(v);
		adjacencyList[v].push_back(u);

	}

	

};


//what is articulation point 
//=>>>> A point which if removed from the graph then will form more than 1 components in the graph


void dfs(int node, int parent,int &timer, vector<int>& discoveryTime, vector<int>& lowestTime, unordered_map<int, bool>& visited, vector<int>& ans , unordered_map<int , list<int> > &adjList) {

	//mark the visit of the node
	visited[node] = 1;

	//initially the discovery & lowest time is that of timer ( post incrememnt it )
	discoveryTime[node] = lowestTime[node] = timer++;

	//to track the no of child of a node ( required to check if the source node is a articulation point too or not )
	int child = 0;

	for (auto adjNode : adjList[node]) {

		//if the adjacentNode is the parent ignore it & move to the next node
		if (adjNode == parent) {
			continue;
		}
		
		//if the node is not visited yet
		if (!visited[adjNode]) {

			//call recursively for it
			dfs(adjNode, node, timer, discoveryTime, lowestTime, visited, ans, adjList);

			//while returning update its lowest time ( in case its' child had a back edge so its lowest time would also decrease)
			lowestTime[node] = min(lowestTime[node], lowestTime[adjNode]);

			//check if its a articulation point or not

			//here the source node as AP case isn't handled

			//if the lowest time of child is greater of discory time of node then it cant be reached by any other node
			//hence it will form a disconnected component

			if (lowestTime[adjNode] >= discoveryTime[node] && parent != -1) {
				//push to answer vector
				ans.push_back(node);
			}

			//increment a child for the node
			child++;

		}

		//back edge i.e => the adjNode is visited && the NODE isnt its parent too
		else {
			//back edge case
			//upadate the low of node with min of itself or discoveryTime of adjNode
			lowestTime[node] = min(lowestTime[node], discoveryTime[adjNode]);

		}

	}

	//source node handling
	//if it has more than 1 child and is source i.e parent -1
	if (child > 1 && parent ==-1) {
		ans.push_back(node);
	}

}






int main() {


	//creating a graph
	graph g;

	int nodes=5;


	g.createConnection(1,0);
	g.createConnection(0,4);
	g.createConnection(1,4);
	g.createConnection(2,3);
	g.createConnection(2,4);
	g.createConnection(3,4);


	


	//required data structures

	//to track timer at time of discovery of a node
	vector<int> discoveryTime(nodes);
	//tracks the lowest possible unit time to reach a node
	vector<int> lowestTime(nodes);
	//visited true/false
	unordered_map<int, bool > visited;

	//souce node
	int source = 0;

	//initializing all the ds with null (-1)
	for (int i = 0; i < nodes; ++i) {
		
		discoveryTime[i] = -1;
		lowestTime[i] = -1;
	
	}

	//starts from  source whose parent is always null
	int parent = -1;
	//the timer 
	int timer = 0;

	//result returning vector
	vector<int> ans;

	//dfs calls
	for (int i = 0; i < nodes; i++) {
		if (!visited[i]) {
			dfs(i, parent, timer, discoveryTime, lowestTime, visited, ans, g.adjacencyList);

		}
	}



	//cout << "Ready" << endl;

	//printing out the ans
	for (auto j : ans) {
		cout << j << " ";
	}
	cout << endl;


	return 0;
}
