#include<iostream>
#include<vector>
using namespace std;

class trieNode {

public:

	char data;
	trieNode* children[26];
	bool isTerminal;

	trieNode(char ch) {
		this->data = ch;
		for (int i = 0; i < 26; ++i) {
			this->children[i] = NULL;
		}
		this->isTerminal = false;

	}


};


class trie {

public:

	trieNode* root;


	trie() {
		this->root = new trieNode('\0');
	}


		void insertUtility(trieNode* root, string word) {

			if (word.length() == 0) {
				root->isTerminal = true;
				return;
			}

			int index = word[0] - 'a';
			trieNode* child;

			if (root->children[index] != NULL) {

				child = root->children[index];

			}
			else {
				child = new trieNode(word[0]);
				root->children[index] = child;
			}

			insertUtility(child, word.substr(1));

		}

	void insertWord(string word) {
		insertUtility(root, word);
	}




		void currSuggestions(trieNode* curr, vector<string> &temp, string pre) {

			//if the node points to a terminal node push to temp & continue
			if (curr->isTerminal == true) {
				temp.push_back(pre);

			}

			//next node ptr
			trieNode* next;

			//traverse all ch for root node
			for (char ch = 'a'; ch <= 'z'; ++ch) {

				next = curr->children[ch - 'a'];

				//if next exists
				if (next != NULL) {
					//push the ch to prefix coming in
					pre.push_back(ch);
					//recursive call with next node ptr as root
					currSuggestions(next, temp, pre);

					//while returning clear the addition to the prefix string
					pre.pop_back();

				}

			}

		}


	vector<vector<string> > giveSuggestion(string prefix) {

		//answer variable
		vector<vector<string> >  ans;
		//initiating node as root
		trieNode* prev = root;

		//traversing string for calls
		string pre = "";
		//temporary vector to store data of each character of input string
		vector<string> temp;

		//traverse through all characters in the curr node
		for (int i = 0; i < prefix.size(); ++i) {

			char ch = prefix[i];

			//push it to pre
			pre.push_back(ch);

			//check if curr exists
			trieNode* curr = prev->children[ch - 'a'];

			//if it doesnt break away
			if (curr == NULL) {
				break;
			}
			
			//it does
			//so call for this characters suggestions
			currSuggestions(curr, temp, pre);
			//temp has the suggestions for this character

			//push it & clear temp for next iteration
			ans.push_back(temp);
			temp.clear();

			//update prev ptr node
			prev = curr;
		}



		return ans;
	}

};




int main() {

	//making a trie
	trie* main = new trie();

	//inputs
	string prefix = "coding";
	vector<string> input = {};


	//putting all the input strings to tthe trie
	for (int count = 0; count < input.size(); ++count) {
		main->insertWord(input[count]);
	}

	//calling for ans
	vector<vector<string> > ans = main->giveSuggestion(prefix);



	return 0;
}