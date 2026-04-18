#include <bits/stdc++.h>
#include "tools.h"
using namespace std;

// Bottom - up
int cherryPickup(matrix &space) {
    int n = space.size();

    matrix memo(n, vector<int>(n, 0));

    int cherry = 0;

    

    return cherry;
}

int main() {
    matrix space(3, vector<int>(3, 0));
    createSpace(space, -1, 1);

    printMatrix(space);

    cout << cherryPickup(space) << "\n";

    return 0;
}