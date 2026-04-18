#include <bits/stdc++.h>
using namespace std;

// Top - down
int fibHelper(int n, vector<int> &fibs) {
    if (n <= 1) return n;

    // If fib(n) existed
    // Get and return it
    // Saving time
    if (fibs[n] != -1) return fibs[n];
    
    // Else
    // Assign value for it
    // And return the value
    return fibs[n] = fibHelper(n - 1, fibs) + fibHelper(n - 2, fibs);
}

// Bottom - up
int fibHelper(int n, vector<int> &fibs) {
    // Set up initally
    fibs[0] = 0; fibs[1] = 1;

    // Loop from 2 to n
    for (int i = 2; i <= n; i++) {
        fibs[i] = fibs[i - 1] + fibs[i - 2];
    }

    return fibs[n];
}

int fib(int n) {
    // Create a memory with a big size to avoid
    // stack overflow
    vector<int> fibs(1000, -1);
    return fibHelper(n, fibs);
}

int main() {
    cout << fib(5) << "\n";
    return 0;
}