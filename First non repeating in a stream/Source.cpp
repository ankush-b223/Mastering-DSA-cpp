#include <iostream>
#include<unordered_map>
#include<queue>
using namespace std;


string solve(string ip) {

	unordered_map<char, int> frequency;
	queue<int> q;

	string answer;

	//with each iteration (++count) new stream is checked
	for (int count = 0; count < ip.size(); ++count) {

		//character in current iteration is stored
		char ch = ip[count];

		//frequencies of characters are stored in this map
		frequency[ch]++;

		//current character is pushed to queue
		q.push(ch);

		//checking if repeating or non repating
		while (!q.empty()) {
			if (frequency[q.front()] > 1) {
				q.pop();
			}
			else {
				//updating answer
				answer.push_back(q.front());
				break;
			}
		}

		//if no non repeating character is found
		if (q.empty()) {
			answer.push_back('#');
		}


	}

	return answer;

}





int main() {

	string input = "aabc";

	string ans = solve(input);

	cout << ans << endl;


	return 0;
}