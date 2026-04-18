#include <iostream>
#include <vector>
using namespace std;

int main() {
    /*
        ==============================
                NORMAL ARRAY
        ==============================
    */
    int arr[] = {1,2,3,4,5}; // Array store integers
    cout << arr[0] << "\n"; // Get the first value --> 1

    /*
        ==============================
                DYNAMIC ARRAY
        ==============================
    */
    // Allocate integer array with size is 10
    // You must use *var because new will return the address
    // Of the first value in array
    int *arrD = new int[10];


    //  Assign the value for each element
    for (int i = 0; i < 10; i++)
        arrD[i] = i;


    // Print array
    for (int i = 0; i < 10; i++)
        cout << arrD[i] << " ";

    /*
        =================================
                    VECTOR
        =================================
    */
   // Create an integer array
    vector<int> v = {1,2,3,4,5};

    cout << v[0] << "\n"; // Access the first of the element at 0

    // Data is a function which return the address of the first element
    // arr.data() + 1 is translate to the next element
    // *(arr.data() + 1) == arr[1]
    cout << *(v.data() + 1) << "\n";
}