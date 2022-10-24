#include<iostream>
using namespace std;

//the trie's node class
class trieNode {

public:

	//a node in a trie would contain
	
	//data
	char data;
	//array pointer having array with all [possible 26 further nodes]
	trieNode* children[26];
	//is it a terminal node or not>>
	bool isTerminal;

	//constructor to create a trieNode
	trieNode(char data) {
		this->data = data;
		//initialize the entire node array as NULL
		for (int i = 0; i < 26; ++i) {
			this->children[i] = NULL;
		}
		//no node is terminal without insertion so initially>>
		isTerminal = false;
	}

};

// the trie data structure
class trie {

public:

	//it has a root trieNode
	trieNode* root;

	//constructor to initialize the trie with a root ( \0 null as it data value )
	trie() {
		this->root = new trieNode('\0');
	}




		//the isnertion utitlity fn 
		void insertUtil(trieNode* &root, string word) {

			//base case
			//if the word reading is done
			if (word.length() == 0) {
				//make the base node as the terminal node
				root->isTerminal = true;
				//return
				return;
			}

			//get the index of the first word of the string
			//index of the char in the children array of a node
			int index = word[0] - 'A';
			//creating a traversing node as child
			trieNode* child;

			//if the children[index] is not null ==>> a node of such exists
			if (root->children[index] != NULL) {
				//so update child to the children[index] node
				child = root->children[index];
			}
			//such a node(index) doesnt exist so make one
			else {
				// making a trieNode and allotting it to child
				child = new trieNode(word[0]);

				//updating the value of child in the root's children array as not null
				root->children[index] = child;
			}


			//recusive call 
			//sending child as root for next call & substringing the word string by removing the first char
			insertUtil(child, word.substr(1));

		}

	void insertWord(string word) {
		//calling the respective utility fn
		insertUtil(root, word);
	}







		//search utility fn
		bool searchUtil(trieNode* root, string word) {

			//base case
			if (word.length() == 0) {

				return root->isTerminal;
			}

			//fetching index if first char in word
			int index = word[0] - 'A';
			//creating the traversing node liek temp
			trieNode* child;
			
			//if the current children[index] node exists
			if (root->children[index] != NULL) {
				//update child
				child = root->children[index];
			}
			else {//doesnt exist so false
				return false;
			}

			//return recusive call
			return searchUtil(child, word.substr(1));
		}



	bool searchWord(string word) {
		//calling the respective utility fn
		return searchUtil(root, word);
	}







		void deleteUtil(trieNode* &root, string word) {

			//base case
			if (word.length() == 0) {
				//terminal node reached

				//unmark it as terminal node
				root->isTerminal = false;
				return;
			}

			//fetch index
			int index = word[0] - 'A';
			//make traversing trieNode
			trieNode* child;

			//move down 
			//assuming not null as the search fn returned true for it ( it exists )
			child = root->children[index];

			//recursive call
			deleteUtil(child, word.substr(1));

		}



	void deleteWord(string word) {

		//checking if the word given exists or not
		if (!searchWord(word)) {
			cout << "Such word doesnt exist" << endl;
		}
		else {	//calling the respective utility fn
			deleteUtil(root, word);
		}
		//word deleted from trie

	}






		//prefix utility fn
		bool prefixUtil(trieNode* root, string prefix) {

			//base case 
			if (prefix.length() == 0) {
				//reached till here so prefix exists 

				//true
				return true;
			}

			//traverse 
			int index = prefix[0] - 'A';
			trieNode* child;

			//check for children[index] ,, if not null >> update child
			if (root->children[index] != NULL) {
				child = root->children[index];
			}
			else {//doesnt exist so false
				return false;
			}

			//return recursive calls
			return prefixUtil(child, prefix.substr(1));
		}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		//calling the respective utility fn
		return prefixUtil(root, prefix);
	}


};



//trie vs hashmaps
// trie has minimal redundancy
// trie utilizes space optimally






int main() {

	//creating a trie
	trie* main = new trie;

	//inserting words to it
	main->insertWord("ARM");
	main->insertWord("DO");
	main->insertWord("TIME");


	//checking the search fn
	if ( main->searchWord("ARM")) {
		cout << "Present" << endl;
	}
	else {
		cout << "Not Present" << endl;
	}

	//checking the delete fn
	main->deleteWord("ARM");

	if (main->searchWord("ARM")) {
		cout << "Present" << endl;
	}
	else {
		cout << "Not Present" << endl;
	}


	return 0;
}