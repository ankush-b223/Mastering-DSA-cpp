#include<limits.h>
#include<stack>
using namespace std;

class SpecialStack {


    // Define the data members.
    stack<int> stck;
    int mini;

public:

    //constructor
    SpecialStack() {

        this->mini = -1;
    }

    /*----------------- Public Functions of SpecialStack -----------------*/
public:

    //to push into special stack
    void push(int data) {

        if (stck.empty()) {
            stck.push(data);
            mini = data;

            return;
        }

        stck.push(data);

        mini = min(mini, data);

        return;

    }
        //to fetch min of a stack utility fn
        int fetchMin(stack<int> stck) {

            //base case
            if (stck.empty()) {
                return INT_MAX;
            }

            //store top 
            int data = stck.top();
            //pop it
            stck.pop();

            //recursive call
            int res = fetchMin(stck);

            //push back stored dara
            stck.push(data);

            //update the min on the way using current data and received min from recc calls
            int ans = min(res, data);

            return ans;
        }

    //to pop from special stack
    int pop() {
        // Implement the pop() function.

        //if stck is emepty
        if (stck.empty()) {
            return -1;
        }

        //top return store the top before popping
        int send = stck.top();

        //pop
        stck.pop();

        //fetch the min of curr stack after pop
        mini = fetchMin(stck);

        //return stored top which has been popped
        return send;
    }

    //returns the top
    int top() {
        if (stck.empty()) {
            return -1;
        }

        return stck.top();
    }

    //to check if special stack is empty or not
    bool isEmpty() {
        if (stck.empty()) {
            return true;
        }
        return false;
    }

    //our special stack's main fn to return the min value in stack
    int getMin() {

        return mini;

    }
};





//driver code
int main() {



    return 0;

}