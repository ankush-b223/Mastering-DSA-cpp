#include<iostream>
#include<vector>
using namespace std;


class trieNode {

public:

	char data;
	trieNode* children[26];
	//child count is added as a data member for this particular problem
	int childCount;
	bool isTerminal;

	trieNode(char ch) {
		this->data = ch;
		this->childCount = 0;
		this->isTerminal = false;

		for (int i = 0; i < 26; ++i) {
			this->children[i] = NULL;
		}
	}
};


class trie {

public:

	trieNode* root;

	trie() {
		this->root = new trieNode('\0');
	}




		void insertUtility(trieNode* &root , string word) {

			if (word.length() == 0) {
				root->isTerminal = true;

				return;
			}

			int index = word[0] - 'a';
			trieNode* child;

			if (root->children[index] != NULL) {
				child = root->children[index];
			}
			else {//inserting a new trieNdoe
				child = new trieNode(word[0]);
				//while inserting increase the childCount as we are making a child of the root node
				root->childCount++;

				root->children[index] = child;
			}

			insertUtility(child, word.substr(1));
			

		}


	void insertWord(string word) {
		insertUtility(root, word);
	}

	//main fn
	void longestCommonPrefix(trieNode* root, string word , string &ans) {

		//first string is checked

		//base case
		if (word.length() == 0) {
			return;
		}
		//if the root is terminal node
		if (root->isTerminal) {
			return;
		}

		//if the childCount of the curr node is more than 1 return
		if (root->childCount > 1) {
			return;
		}

		//if all such exclusion cases  arent true then 

		//fetch first character from word and push to ans string
		char ch = word[0];
		ans.push_back(ch);

		//update child & dive down
		trieNode* child;
		int index = ch - 'a';
	
		child = root->children[index];

		//recursive call
		longestCommonPrefix(child, word.substr(1), ans);
	
	}


};










int main() {

	//making a trie
	trie* main = new trie();

	//input strings
	vector<string> input= { "coding", "codezen", "codingninja", "coder"};

	//pushing all strings to the trie
	for (int count = 0; count < input.size(); ++count) {
		main->insertWord(input[count]);
	}



	//fetching the first string from the input of strings
	string first = input[0];


	//making ans string
	string ans;
	//calling for lcp fn
	main->longestCommonPrefix(main->root, first , ans);

	//printing out ans
	cout << ans << endl;        


	return 0;
}




/*

//better solution with lesser space complexity



string longestCommonPrefix(vector<string> &arr, int n)
{
    
      string ans;

    for (int count = 0; count < arr[0].size(); ++count) {
        char ch = arr[0][count];
        bool match=1;
        for(int test =1 ; test< arr.size() ; ++test ){
            char check = arr[test][count];

            if(arr[test].size()<count){
                match=0;
                break;
            }

            if(ch == check){
                match=1;
            }

            else{
                match =0;
                break;
            }

        }

        if(match){
            ans.push_back(ch);
        }
        else{
            break;
        }

    }


    return ans;

}




*/