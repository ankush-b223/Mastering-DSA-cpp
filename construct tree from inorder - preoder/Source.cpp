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

void postOrder(node* root) {
	//lrn

	if (root == NULL) {
		return;
	}

	postOrder(root->left);
	postOrder(root->right);

	cout << root->data << " ";



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

//find postion of elelemnt in inorder array
int findposition(int in[], int element, int size) {
	for (int count = 0; count < size; ++count) {
		if (in[count] == element) {
			return count;
		}
	}

}

//the arrays , preIndex by ref , inStartIndex, inEndIndex . size of arr as args
//fn def
node* solve(int in[], int pre[], int& preIndex, int inStart, int inEnd, int size , map<int,int> nodeToindex) {

	//base case if the index of any array runs out
	if (preIndex >= size || inStart > inEnd) {
		return NULL;
	}

	//fetch element and increment index from pre arr
	int element = pre[preIndex++];
	//create new node
	node* root = new node(element);

	//find the postion of element in inorder arr
	int position = nodeToindex[element];

	//recurisve calls to create left & right parts of tree
	root->left = solve(in, pre, preIndex, 0, position - 1, size,nodeToindex);
	root->right = solve(in, pre, preIndex, position + 1, inEnd, size,nodeToindex);

	//return root
	return root;



}

//map creating fn
//attaches element to its index
void createMap(map<int, int> &nodeToIndex, int in[], int size) {

	for (int count = 0; count < size; ++count) {
		nodeToIndex[in[count]] = count;

	}

}

//returns root node of tree created
node* buildIN_PRE( int in[], int pre[], int n) {

	//index maintainer of preOrder array
	int preIndex = 0;

	//declare map and create it
	map<int, int> nodeToIndex;
	createMap(nodeToIndex, in, n);
	
	node* ans = solve( in, pre, preIndex, 0, n - 1, n , nodeToIndex);

	return ans;

}





int main() {

	int pre[5] = { 1, 6, 7, 8 };
	int in[5] = { 1, 6, 8, 7 };


	int size = 4;

	node* root = buildIN_PRE(in, pre, size);
	
	//buildIN_PRE( in, pre, size);

	postOrder(root);

	
	return 0;

}