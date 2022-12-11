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

//max variables are called by reference
void solve(node* root, int sum, int& maxSum, int len, int& maxLen) {
	//base case
	if (root == NULL) {

		//if len is greater than maxLen
		if (len > maxLen) {
			maxLen = len;
			maxSum = sum;
		}

		//if equal len then look for max of both sums (i.e sum & maxSum)
		else if (len == maxLen) {
			maxSum = max(maxSum, sum);
		}

		return;

	}

	//add root data to sum with each call
	sum += root->data;

	//recursive calls with increase in length  (+1) 
	solve(root->left, sum, maxSum, len + 1, maxLen);
	solve(root->right, sum, maxSum, len + 1, maxLen);




}

//returning fn
int sumLongPath(node* root) {

	//initialize 4 variables
	int sum = 0;
	int maxSum = 0;

	int len = 0;
	int maxLen = 0; 

	solve(root, sum, maxSum, len, maxLen);

	//return maxSum
	return maxSum;



}




int main() {

	node* root = NULL;

	buildTree(root);

	int ans = sumLongPath(root);


	cout << ans << endl;

	return 0;
}