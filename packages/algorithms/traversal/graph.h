#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


class Graph {
    public:
        Graph(vector<int> nums) : nums(nums) {
            // Create size for matrix and list
            matrix.resize(nums.size(), vector<int>(nums.size(), 0));
            for (int el : nums) list[el] = {};
        }


        pair<map<int, vector<int>>, vector<vector<int>>> get_graph() {
            return {list, matrix};
        }


        void addEdge(int v1, int v2) {
            // Add connection in list
            list[v1].push_back(v2); list[v2].push_back(v1);
            // Add connection in matrix
            matrix[v1][v2] = 1; matrix[v2][v1] = 1;
        }


        void print_matrix() {
            cout << "  ";
            for (int i = 0; i < nums.size(); i++) cout << i << " ";
            cout << endl;
            for (int i = 0; i < nums.size(); i++) {
                cout << i << " ";
                for (int j = 0; j < nums.size(); j++) {
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }
        }


        void print_list() {
            for (auto element : list) {
                cout << element.first << ": ";
                for (int x : element.second) cout << x << " ";
                cout << endl;
            }
        }


        void removeVertex(int vertex) {
            if (list.find(vertex) != list.end()) {
                list.erase(vertex);
                for (auto& element : list) {
                    auto& nums = element.second;
                    nums.erase(remove(nums.begin(), nums.end(), vertex));
                }


                for (int i = 0; i < nums.size(); i++) {
                    matrix[i][vertex] = 0;
                    matrix[vertex][i] = 0;
                }
            }
        }


    private:
        map<int, vector<int>> list;
        vector<vector<int>> matrix;
        vector<int> nums;
};
