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

//fn def
vector<int> topView(node* root) {

	//ans returning vector
	vector<int> ans;

	//map to store horizontleDistance along with nodeData
	map<int, int> nodeMap;

	//queue storing node and horDist
	queue<pair<node*, int> > q;

	//underflow
	if (root == NULL) {
		return ans;
	}

	//pushing root
	q.push(make_pair(root, 0));

	//till queue is empty
	while (!q.empty()) {
		//fetch frist queue element
		pair<node*, int> temp = q.front();
		//pop it
		q.pop();

		//fetch details from front queue element
		node* frontNode = temp.first;
		int horDist = temp.second;
		
		//if for that corresponding horDist data doesnt exist already in map 
		//then push current node data to map
		//if data doesnt exist to that horDist then it is equal to map's end so the args
		if (nodeMap.find(horDist) == nodeMap.end()) {
			nodeMap[horDist] = frontNode->data;
		}

		//traverse left and right keeping horDist stable
		if (frontNode->left) {
			q.push(make_pair(frontNode->left, horDist - 1));
		}
		
		if (frontNode->right) {
			q.push(make_pair(frontNode->right, horDist + 1));
		}

	}

	//fetch the node datas from map and push to ans vector
	for (auto i : nodeMap) {
		ans.push_back(i.second);
	}

	return ans;
}







int main() {

	node* root = NULL;

	buildTree(root);

	leveltraversal(root);
	cout << endl;

	vector<int> result = topView(root);

	for (auto i : result) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}