#include<iostream>
#include<unordered_map>
#include<stack>
using namespace std;


class graph {

public:

	unordered_map<int, list<pair<int, int> > > adjacencyList;

	void makeConnection(int u, int v, int weight) {

		pair<int, int> p = make_pair(v, weight);

		adjacencyList[u].push_back(p);

	}


	void printList() {

		for (auto i : adjacencyList) {
			cout << i.first << "-> ";

			for (auto j : i.second) {
				cout << "[ " << j.first << " , " << j.second << " ]";
			}
			cout << endl;
		}

	}


};




void topoDFS(int node, unordered_map<int, bool>& visited, stack<int>& topoStck, unordered_map<int, list<pair<int, int> > >& adjacencyList) {

	visited[node] = 1;

	for (auto i : adjacencyList[node]) {
		if (!visited[i.first]) {
			topoDFS(i.first, visited, topoStck, adjacencyList);
		}
	}

	topoStck.push(node);

}











int main() {

	//making the graph
	graph g;

	g.makeConnection(0, 1, 5);
	g.makeConnection(0, 2, 3);
	g.makeConnection(1, 2, 2);
	g.makeConnection(1, 3, 6);
	g.makeConnection(2, 3, 7);
	g.makeConnection(2, 4, 4);
	g.makeConnection(2, 5, 2);
	g.makeConnection(3, 4, -1);
	g.makeConnection(4, 5, -2);



	//g.printList();

	//the amount of nodes in the particular graph
	int nodes = 6;

	//creating data structures required for topological Sort

	//why topological sort
	//the sort will give us a linear order where I can assume the elements appearing before actually come before in the graph to apply the algo

	unordered_map<int, bool> visited;
	stack<int> topoStck;

	for (int count = 0; count < nodes; ++count) {
		if (!visited[count]) {
			topoDFS(count, visited, topoStck, g.adjacencyList);
		}
	}

	//stack is ready with topological ordering

	//answer vetor containing all the distances from souce node
	vector<int> distance(nodes);

	//initializing the entire answer vector with INTMAX, assumming no node is directed from source node
	for (int test = 0; test < nodes; ++test) {
		//intMAX is basically assummed infinty here
		distance[test] = INT_MAX;
	}

	//source node declaration
	int source = 1;

	//the distance of source node is declared as 0
	distance[source] = 0;


	//till the stack is empty
	while (!topoStck.empty()) {

		//fetch the top element from the stck & pop it
		int top = topoStck.top();

		topoStck.pop();

		//if the distance of fetched top is not INT_max
		//if its int max it means that the top node isnt directed with source node

		if (distance[top] != INT_MAX) {

			//fetch all its neighbouring nodes
			for (auto k : g.adjacencyList[top]) {

				//if the sum of weight of adjacentNode & existing distance of top ( see topNode not adjacentNode )
				//is less than the already existing distance of adjacentNode( here k )
				//then update distance of adjacentNode (k)

				//.first & and second as the the adjacency list is saved in pair
				if (k.second + distance[top] < distance[k.first]) {
					distance[k.first] = k.second + distance[top];
				}

			}

		}




	}



	//printing out answer
	for (auto a : distance) {
		cout << a << " , ";
	}
	cout << endl;




	return 0;
}