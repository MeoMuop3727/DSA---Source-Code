#pragma once
#include <vector>
#include <iostream>

typedef std::vector<std::vector<int>> matrix;
typedef std::vector<matrix> matrix3D; 

// void printMatrix(matrix &space) {
//     int n = space.size();
//     int m = space[0].size();

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) 
//             cout << space[i][j] << " ";
//         cout << "\n";
//     }
// }

void printMatrix(matrix &space) {
    for (auto &row : space) {
        for (int &e : row)
            std::cout << e << " ";
        std::cout << "\n";
    }
}

void forEach(std::vector<int> &arr) {
    for (int &e : arr)
        std::cout << e << " ";
    std::cout << "\n";
}

void createSpace(matrix &space, int a, int b) {
    srand(time(NULL));
    
    for (auto &row : space)
        for (int &e : row)
            e = rand() % (b - a + 1) + a;
}