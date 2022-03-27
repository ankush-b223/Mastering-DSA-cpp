#include <iostream>
using namespace std;
#include <cstring>



string sortSentence(string s) {

    int count = 0, test = 0;

    char string[100];
    int check = 0, counter = 0;
    int index = 0;
    int nword = 0;

    for (count = 0; count < s.length(); ++count) {
        if (s[count] == ' ') {
            index += 1;
            s[count - 1] = check;
            check = check - 1;

            for (test = index; test < counter - 1; ++test) {
                s[test] = string[];
                ++nword;
            }

            string[nword] = ' ';
            ++nword;
            counter = 0;
            continue;

        }
        else {
            counter += 1;
            index += 1;

        }
    }

    string[nword] = '\0';

    return string;
}

void display_string(string s) {
    int count = 0;
    while (count < s.length()) {
        cout << s[count];
        ++count;
    }
}

int main() {

    char string[100] = "Myself2 Me1 I4 and3";

    cout <<sortSentence(string);

    




}