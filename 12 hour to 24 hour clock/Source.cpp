#include <iostream>
#include <string>
using namespace std;


string timeConversion(string s) {

    string result;
    // string to char_array
    char AMorPM = s[8];
    char* char_array;
    char_array = &s[0];

    char stro[100];

    if (AMorPM == 'P') {
        // edge case of 12 pm
        if (char_array[0] == '1' && char_array[1] == '2') {
            result = s.substr(0, 8);
        }
        else {

            stro[0] = char_array[0];
            stro[1] = char_array[1];
            // the maths i.e just (+12)
            int test = stoi(stro) + 12;

            string a = to_string(test);
            string r = s.substr(2, 6);


            result = a + r;
        }
    }
    else {
        //edge case as stated
        if (s == "12:00:00AM") {
            result = "00:00:00";
        }
        //edge case of 12 am xcept 12:00:00amstring timeConversion(string s) {

        string result;
        char AMorPM = s[8];
        char* char_array;
        char_array = &s[0];
        char stro[100];

        if (AMorPM == 'P') {
            if (char_array[0] == '1' && char_array[1] == '2') {
                result = s.substr(0, 8);
            }
            else {

                stro[0] = char_array[0];
                stro[1] = char_array[1];
                int test = stoi(stro) + 12;

                string a = to_string(test);
                string r = s.substr(2, 6);


                result = a + r;
            }
        }
        else {
            if (s == "12:00:00AM") {
                result = "00:00:00";
            }
            else if (char_array[0] == '1' && char_array[1] == '2') {
                string a;
                a = "00";
                string r = s.substr(2, 6);
                result = a + r;
            }
            else {
                result = s.substr(0, 8);
            }
        }

        return result;
    }

        else if (char_array[0] == '1' && char_array[1] == '2') {
        string a;
        a = "00";
        string r = s.substr(2, 6);
        result = a + r;
        }
        else {
        result = s.substr(0, 8);
        }
}

return result;
}



