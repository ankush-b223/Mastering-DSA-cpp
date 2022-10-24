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

	cout << "Enter no of nodes & edges " << endl;
	int n, e;
	cin >> n >> e;

	for (int count = 0; count < e; ++count) {

		cout << "Enter node data" << endl;
		int u, v;

		cin >> u >> v;

		g.createConnection(u, v);

	}

	//cout << "Hello" << endl;


	vector<int> indegree(n);



	for (auto i : g.adjacencyList) {

		for (auto j : i.second) {
			indegree[j]++;
		}
	}
	
	vector<int> ans;
	queue<int> q;

	for (int count = 0; count < n;++count) {
		if (indegree[count] == 0) {
			q.push(count);
		}
	}

	while (!q.empty()) {

		int front = q.front();

		q.pop();
		
		ans.push_back(front);
		
		for (auto i : g.adjacencyList[front]) {

			indegree[i]--;

			if (indegree[i] == 0) {
				q.push(i);
			}

		}

	}

	for (auto k : ans) {
		cout << k << " ";
	}
	cout << endl;



	return 0;
}
