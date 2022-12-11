#include<iostream>
#include<queue>
#include<map>
using namespace std;


class node {

public:

	int data;
	node* left;
	node* right;


	node(int d) {
		this->data = d;
		this->left = NULL;
		this->right = NULL;
	}
};


node* buildTree(node*& root) {

	cout << "Enter data" << endl;
	int d;
	cin >> d;

	root = new node(d);

	if (root->data == -1) {
		return NULL;
	}


	cout << "enter element to be inserted in the left of " << root->data << endl;
	root->left = buildTree(root->left);

	cout << "enter element to be inserted in the right of " << root->data << endl;
	root->right = buildTree(root->right);


	return root;


}

void leveltraversal(node* root) {

	queue<node*>q;

	q.push(root);
	q.push(NULL);

	while (!q.empty()) {

		node* temp = q.front();
		q.pop();

		if (temp == NULL) {
			cout << endl;

			if (!q.empty()) {

				q.push(NULL);
			}

		}
		else {

			cout << temp->data << " ";

			if (temp->left) {
				q.push(temp->left);
			}
			if (temp->right) {
				q.push(temp->right);
			}

		}


	}

}


//creates mapping node to parent as well as finds taget node
node* createMapping(node* root, int target, map<node*,node*>& nodetoParent) {
	//queue for LOT
	queue<node*> q;
	//taget node
	node* result = NULL;

	//push root
	q.push(root);

	//map root node to null as >> root node father is nULL
	nodetoParent [ root ] = NULL ;

	//start loop
	while (!q.empty()) {

		//fetch fist element & pop it
		node* temp = q.front();
		q.pop();

		//if front node is target node store it
		if (temp->data == target) {
			result = temp;
		}

		//LOT logic + map the temp-> left/ right to their father which is temp itself
		if (temp->left) {
			q.push(temp->left);
			nodetoParent[temp->left] = temp;
		}
		if (temp->right) {
			q.push(temp->right);
			nodetoParent[temp->right] = temp;
		}


	}

	//return target node
	return result;

}



//main fn def
int solve(node* root, int target, map<node*, node*> nodeToParent) {
	//queue for LOT
	queue<node*> q;
	//time =0 iniitialization
	int time=0;

	//creating a visited map
	map<node*, bool> visited;

	//root here is target node 

	//pushing target node
	q.push(root);
	//marking its visit as true
	visited[root] = 1;

	//LOT loop
	while (!q.empty()) {


		int size = q.size();
		//flag >> traversal happende >> burning happened
		bool flag = 0;

		//iterates through entire queue one by one
		for (int count = 0; count < size; ++count) {

			//fetching first node & pooping it
			node* temp = q.front();
			q.pop();
			//make flag false in start 
			flag = 0;

			//if left exists & its not yet burned / visited
			if (temp->left && !visited[temp->left]) {
				//make flag as as travesal or insertion to queue took place 
				flag = 1;
				//push to queue
				q.push(temp->left);
				//mark its visit
				visited[temp->left] = 1;
			}

			//same as left 
			if (temp->right && !visited[temp->right]) {

				flag = 1;
				q.push(temp->right);
				visited[temp->right]= 1;
			}

			//traversing up 

			//check if parent node exist & if its visited or not
			if (nodeToParent[temp] && !visited[nodeToParent[temp]]) {
				flag = 1;
				visited[nodeToParent[temp]] = 1;
				q.push(nodeToParent[temp]);
			}


		}

		//if traversal/pushing took place increment time
		if(flag){
			time++;
		}

	}

	return time;
}




//answer returning function
int burnTree(node* root, int target) {

	//creating node to parent map
	map<node*,node*> nodeToParent;

	//getiing the target node & also creating map node to parent
	node* targetNode = createMapping(root, target, nodeToParent);

	//calling main time calculationg fn using target node as root node arg call
	int time = solve(targetNode, target, nodeToParent);

	//returning ans
	return time;


}


















int main() {

	node* root = NULL;

	buildTree(root);

	int ans = burnTree(root, 8);

	cout << ans << endl;



	return 0;
}