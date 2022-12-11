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
		this ->left = NULL;
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

//fn def
 vector<int> verticalTraversal(node* root) {
	
	 //ans returning vector
	vector<int> ans;
	
	//map to store values format ->  map - > int[horizontleDistance] , map 
	//( int [level ] , vector<int> to store root data )  

	map<int, map< int, vector<int> > > nodes;
	// two pairs ..>> pair 1 - node* , pair2 __>> int(hd) ,int(level)
	queue< pair< node*, pair< int, int> > > q;

	//underflow
	if (root == NULL) {
		return ans;
	}
	
	//push root data to queue
	q.push(make_pair(root, make_pair(0, 0)));

	//till queue is empty
	while (!q.empty()) {

		//fetch front element
		pair< node*, pair< int, int> > temp = q.front();
		//pop front elelment
		q.pop();	
		
		//fetch these from front element
		node* frontNode = temp.first;
		int horDist = temp.second.first;
		int level = temp.second.second;

		//putting frontnode's data to map
		nodes[horDist][level].push_back(frontNode->data);

		//push left and right elelemnts (dont use post and pre increment here as the data needs to be stable
		if (frontNode->left) {
			q.push(make_pair(frontNode->left, make_pair(horDist-1, level+1)));

		}
		if (frontNode->right) {
			q.push(make_pair(frontNode->right, make_pair(horDist+1, level+1)));
		}


	}

	//fetching the vector from the map and pushing the same to our ans vector
	for (auto i : nodes) {
		for (auto j : i.second) {
			for (auto k : j.second) {
				ans.push_back(k);
			}
		}
	}

	return ans;
}


int main() {


	node* root = NULL;

	buildTree(root);

	leveltraversal(root);
	cout << endl;

	vector<int> result = verticalTraversal(root);

	for (auto i : result) {
		cout << i << " ";
	}

	return 0;
}
