#include<iostream>
#include<unordered_map>
#include<queue>
#include<vector>
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



















int main() {

	graph g;

	cout << "Enter no of nodes & edges" << endl;
	int n, e;

	cin >> n >> e;

	for (int count = 0; count < e; ++count) {
		cout << "Enter node data" << endl;
		int u, v;
		cin >> u >> v;

		g.createConnection(u, v);
	}


	//create required data structures
	unordered_map<int, bool>visited;
	//in this map the parent to a particular node will be stored
	unordered_map<int, int> parent;
	queue<int> q;

	//takes the source & destination
	int source,destination;

	cout << "Enter Source & destination" << endl;
	cin >>source >> destination;

	//push the source
	q.push(source);
	//mark its visit
	visited[source] = 1;
	//make parent of source as -1
	parent[source] = -1;

	//till queue is empty
	while (!q.empty()) {

		//fetch front & pop it
		int front = q.front();
		q.pop();

		//fetch all the adjacent nodes of front
		for (auto k : g.adjacencyList[front]) {
			//if adjacent node is not visited
			if (!visited[k]) {
				//mark its visit
				visited[k] = 1;
				//make the parent of adjacent node [k] i.e node;
				parent[k] = front;

				//push to queue
				q.push(k);
			}

		}

	}
	
	//answer storing / path storing vector
	vector<int> ans;

	//backtracking logic , track from destination
	//fewtch all the parents in the way till source is found
	//current node is like temp iterator here
	int currentNode = destination;

	//push temp
	ans.push_back(currentNode);

	//till source is reached
	while (currentNode != source) {
		//make temp its parent
		currentNode = parent[currentNode];

		//push it ans
		ans.push_back(currentNode);
	}

	//reverse the vector and print the shortest path
	reverse(ans.begin(), ans.end());

	for (auto j : ans) {
		cout << j << " -> ";
	}
	cout << endl;





	return 0;

}
