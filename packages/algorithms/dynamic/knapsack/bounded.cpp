#include <bits/stdc++.h>
#include "../grid-dp/tools.h"
#include "../../add/add.h"
using namespace std;

struct newItems {
    vector<int> values;
    vector<int> weights;
};

newItems binary_splitting(vector<int> &values, vector<int> &weights, vector<int> &counts) {
    int n = values.size();
    newItems items;

    // Traversal all items
    for (int i = 0; i < n; i++) {
        int exp = 0; // Exponent of 2
        int cnt = counts[i]; // The number of times we can get the item
        
        // If 2^exp is smaller than cnt
        // Get it and update cnt, exp
        while (pow(2, exp) <= cnt) {
            int exp2 = pow(2, exp);

            // Add new value and weight to new items
            items.values.push_back(values[i] * exp2);
            items.weights.push_back(weights[i] * exp2);

            // Update cnt, exp
            cnt -= exp2; exp++;
        }

        // Handle the redundant of cnt
        if (cnt > 0) {
            items.values.push_back(values[i] * cnt);
            items.weights.push_back(weights[i] * cnt);
        }
    }

    return items;
}

int main() {
    vector<int> values = {1,2,5,6};
    vector<int> weights = {2,3,4,5};
    vector<int> counts = {2,4,13,1};

    int maxWeight = 24;

    newItems items = binary_splitting(values, weights, counts);

    cout << add_tools::knapsack_bool(items.values, items.weights, maxWeight) << "\n";

    return 0;
}