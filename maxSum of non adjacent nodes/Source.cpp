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
pair<int, int> solve(node* root) {

	//base case
	if (root == NULL) {

		//0,0 ( sum including & excluding both are zero for null nodes )
		pair<int, int> base = make_pair(0, 0);
		return base;
	}

	//recursive calls for left & right 
	pair<int, int> leftAns = solve(root->left);
	pair<int, int> rightAns = solve(root->right);

	//result carrying pair
	pair<int, int> result;

	//res.first will have root data with sum of left and right excluding sums ( second )
	result.first = root->data + leftAns.second+ rightAns.second;
	//second will contain max of left summed with max right 
	result.second = max(leftAns.first, leftAns.second) + max(rightAns.first, rightAns.second);


	return result;



}

//answer returning fn
int sumNadjacent(node* root) {

	//creating pair
	//int 1 = sum including curr node->data
	//int2 = sum excluding curr node->data
	pair<int, int> ans = solve(root);

	//return the max of int1 / int2
	return max(ans.first, ans.second);



}


int main() {

	node* root = NULL;

	buildTree(root);

	cout<<sumNadjacent(root)<<endl;


	return 0;
}