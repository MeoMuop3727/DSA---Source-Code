#pragma once
#include <vector>
#include <iostream>

typedef std::vector<std::vector<int>> matrix; // A vector 2D for int
typedef std::vector<matrix> matrix3D; // A vector 3D for int

template <typename T>
using space2D = std::vector<std::vector<T>>; // A vector 2D for each value

// To print 2D matrixes have size n x m
void printMatrix(matrix &space) {
    for (auto &row : space) {
        for (int &e : row)
            std::cout << e << " ";
        std::cout << "\n";
    }
}

// To print 1D matrixes have size n
void forEach(std::vector<int> &arr) {
    for (int &e : arr)
        std::cout << e << " ";
    std::cout << "\n";
}

// Assign values for 2D matrixes from a to b
void createSpace(matrix &space, int a, int b) {
    srand(time(NULL));
    
    for (auto &row : space)
        for (int &e : row)
            e = rand() % (b - a + 1) + a;
}

// To reverse a string and return new string reversed
std::string to_reverse(std::string str) {
    std::string rev = "";
    for (int i = str.size() - 1; i >= 0; i--)
        rev += str[i];
    return rev;
}


