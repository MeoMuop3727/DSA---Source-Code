#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    /*
        ===================
            STACK
        ===================
    */
    // Create empty stack
    stack<int> st;
    // Push value to stack
    st.push(0); // Empty --> 0
    st.push(1); // 0 --> 1 0
    st.push(2); // 1 0 --> 2 1 0
    // Get the first element
    cout << st.top() << "\n"; // Get 2
    // Delete the top element
    st.pop(); // Delete 2

    /*
        ===============
        MONOTONIC STACK
        ===============
    */
    vector<int> arr = {5,2,3,4,1}; // Save values to build stack
    stack<int> mono_st; // Monotonic Stack
    for (int i = 0; i <= (int)arr.size(); i++) {
        // When the mono_st is not empty
        // And the top is larger than arr[i]
        // In here, if you choose larger than arr[i], we will build increased mono_st
        // Else, we will build decreased mono_st
        while (!mono_st.empty() && mono_st.top() > arr[i]) {
            cout << mono_st.top() << " ";
            mono_st.pop();
        }
        mono_st.push(arr[i]);
    }

    /*
        =============
        MIN/MAX STACK
        =============
    */
    stack<pair<int,int>> min_st; // {value, min value}
    for (int i = 0; i < (int)arr.size(); i++) {
        // If we stack is empty
        // Push element, with the min value = arr[i] initally
        if (min_st.empty()) min_st.push({ arr[i], arr[i] });

        // Else
        // Choose the min value between new value and old value
        else 
            min_st.push({ arr[i], min(
                arr[i],
                min_st.top().second
            )});
    }
    cout << min_st.top().second << "\n"; // Get the min value
}