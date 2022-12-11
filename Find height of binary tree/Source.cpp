#include <iostream>
#include<queue>
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

    cout << "Enter data for " << endl;
    int data;
    cin >> data;


    root = new node(data);


    if (root->data == -1) {
        return NULL;
    }


    cout << "Enter number to be inserted to the left of " << root->data << endl;
    root->left = buildTree(root->left);

    cout << "Enter number to be inserted to the right of " << root->data << endl;
    root->right = buildTree(root->right);


    return root;

}

//using recursion
int height(node* root) {

    //base case
    if (root == NULL) {
        return NULL;
    }


    int left = height(root->left);
    int right = height(root->right);

    //near the base case , leaf nodes return left = 0 , right =0 
    //when it returns formula evaluates , max (0,0) +1 = 1 then further back evaluations are made 
    //to return correct height
    int height = max(left, right) + 1;


    return height;

}



/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
public:
    //Function to find the height of a binary tree.

    int levelOrderTraversal(struct Node* root) {
        int height = 0;

        queue<struct Node*> q;

        q.push(root);
        q.push(NULL);

        while (!q.empty()) {

            struct Node* temp = q.front();
            q.pop();

            if (temp == NULL) {
                ++height;
                if (!q.empty()) {

                    q.push(NULL);

                }


            }

            else {
                if (temp->left != NULL) {
                    q.push(temp->left);
                }
                if (temp->right != NULL) {
                    q.push(temp->right);
                }

            }


        }

        return height;

    }

    int height(struct Node* node) {
        // code here 

        int answer = levelOrderTraversal(node);

        return answer;
    }
};


*/


int main() {

    node* root = NULL;

    buildTree(root);

    int ans = height(root);

    cout << ans << endl;

    return 0;
}

