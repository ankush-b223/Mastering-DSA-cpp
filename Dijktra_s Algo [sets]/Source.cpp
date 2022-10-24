#include<iostream>
#include<set>
#include<list>
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
				cout << "[ " << j.first << " , " << j.second << " ] , ";
			}
			cout << endl;
		}

	}


};


















int main() {

	//creating graph
	graph g;

	g.createConnection(0,1,7);
	g.createConnection(0,2,1);
	g.createConnection(0,3,2);
	g.createConnection(1,2,3);
	g.createConnection(1,3,5);
	g.createConnection(1,4,1);
	g.createConnection(3,4,7);



	//g.printList();

	//declaring no of nodes in graph
	int nodes = 5;

	//declaring ans vector containg the distances from source to all other nodes
	vector<int> distance(nodes);

	//initializing the dist vector with all INT max values as infinty as dist will be smaller than INT_MAX
	for (int count = 0; count < nodes  ; ++count) {
		distance[count] = INT_MAX;
	}

	//getting the source node
	int source = 0;

	//declaring the dist of source in vector as zero
	distance[source] = 0;

	//using set to sort the data being traversed and complete the algo
	//priority queue can also be used instead

	//set contains pair where first -> nodeDistance(to reach that node from source) & second -> nodeNumber
	set<pair<int,int> > st;

	//inserting source value to set
	st.insert(make_pair(0,source));

	//till set is empty
	while (!st.empty()) {

		//fetch the top element
		auto top = *(st.begin());
		//pop it froms set
		st.erase(top);

		//bring out the elements from the top pair obtained above
		int nodeDist = top.first;
		int nodeTop = top.second;


		//visit the adjacent nodes of nodeNUM/NodeTop obtained
		for (auto adjacent : g.adjacencyList[nodeTop]) {

			//if the sum of dist[topNode] with weight of adjacentNode is less than the exisiting value of dist[adjacentNode]
			//then update

			if (distance[nodeTop] + adjacent.second < distance[adjacent.first]) {

				//before updating check the set for any element having same nodeNum & nodedist(exisiting) as a pair
				auto exist = st.find(make_pair(distance[adjacent.first], adjacent.first));

				//if it exists then pop it first
				if (exist != st.end()) {
					//popping
					st.erase(exist);
				}

				//then / otherwise
				//update dist[adjacentNode]
				distance[adjacent.first] = distance[nodeTop] + adjacent.second;

				//insert the new pair having new dist[adjacentNode] with nodeNum as an pair
				st.insert(make_pair(distance[adjacent.first], adjacent.first));

			}

		}

	}






	//printing out the vector having the shortest distances from source node to each & every node
	for (auto k : distance) {
		cout << k << " ";
	}
	cout << endl;







	return 0;
}