#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;


class graph {


public:

	unordered_map<int, list<pair<int, int > > > adj;

};


int findParent(int node , vector<int> &parent) {

	//if the parent is same as node then return it

	//base case
	if (parent[node] == node) {
		return node;
	}

	else {
		//recursive call to find its parent's parent 
		//path compression logic  *******
		//while returning the calls allot the parent of the node to the returning answer from further calls
		return parent[node] = findParent(parent[node], parent);
	}

}

//make a union of the nodes into a component
void makeUnion(int node1,int node2,vector<int> &parent, vector<int> & rank) {

	//fetch the parents of the nodes coming in
	int f1 = findParent(node1,parent);
	int f2 = findParent(node2, parent);

	
	//3 cases

		//if the ranks are not equal
		
	//make bigger node as parent of smaller node
		if (rank[f1] > rank[f2]) {

			//the bigger node becomes the parent 
			parent[f2] = f1;

			//no update in ranks in inequality cases


		}

		else if (rank[f2] > rank[f1]) {

			//same logic as above case
			parent[f1] = f2;
		
			//no update in ranks in inequality cases

		}

		//for same rank case make any node as parent but increase the rank of the node being the parent
		else {

			//f2 is parent node to f1 is being mapped to the parent vector
			parent[f1] = f2;
			//** rank getiing increased

			//the node becoming parent>> that node's rank is getting incremented
			rank[f2]++;
		}

}



//initialize the vectors req to make a disjoint set
void makeSet(vector<int>& rank, vector<int>& parent , int nodes) {

	for (int i = 1; i < nodes; ++i) {
		//self parenting nodes
		parent[i] = i;
		//all ranks are iniially zero so...
		rank[i] = 0;
	}

}



int main() {

	
	int nodes = 6;

	//the required data structures
	vector<int> rank(nodes);
	vector<int> parent(nodes);

	//make the disjoint
	makeSet(rank, parent,nodes);


	//here assume a sorted edges vector as weights as the comparator ascending
/* 	vector<vector<int> > edges;
		0 1 3
		0 3 5
		1 2 1
		2 3 8
*/
	//this is kruskal's algo
	//if the parent nodes are same => they are in same component graph then ignore 
	//else make a union of them and make join each other in a component
	vector<vector<int> > edges;

	//the question wants us to return the weight of the mst possible from he given graph
	//so
	int minWtMST = 0;

	//looping all the nodes
	for (int i = 0; i < edges.size(); ++i) {

		//fetching the nodes + its weights
		int u = edges[i][0];
		int v = edges[i][1];
		int wt = edges[i][2];

		//fetch the parent of coming nodes
		int f1 = findParent(u, parent);
		int f2 = findParent(v, parent);

		//if parents are same >> => that they are already connected so ignore the case

		//not equal parent nodes so the nodes need to be joined ( union ) into a component
		if (f1 != f2) {

			makeUnion(f1, f2, parent, rank);
			//qs req
			minWtMST += wt;

		}

	}

	//return minWtMST
	//this will have the min weight of the mst formed


	return 0;
}