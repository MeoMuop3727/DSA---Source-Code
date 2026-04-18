#include <bits/stdc++.h>
using namespace std;

float Solution(vector<pair<int,int>> &items, int maxWeight) {
    // Sort items according to increase gradually by
    // the proportion of value and weight 
    // The time complexity: O(n logn)
    sort(items.begin(), items.end(), [](auto &a, auto &b) {
        return ((float)a.first / a.second) > ((float)b.first / b.second);
    });

    int w = maxWeight;
    float maxValue = 0;

    // Traversal in sorted items
    for (int i = 0; i < (int)items.size(); i++) {
        // If the weight of current item
        // is fit or smaller than weight
        // Get all them
        // Update maxWeight and maxValue
        if (items[i].second <= w) {
            w -= items[i].second;
            maxValue += items[i].first;
        } 
        // Else
        // Just get part-hal of item according to the proportion
        // w / weight of item
        // Update it to maxValue and break the loop
        else {
            maxValue += items[i].first * ((float)w / items[i].second);
            break;
        }
    }
    
    return maxValue;
}

int main() {
    // pair<int,int> = {value, weight}
    vector<pair<int,int>> items = {
        {1,2}, {2,3}, {5,4}, {6,5}
    };
    int maxWeight = 8;

    cout << Solution(items, maxWeight) << "\n";

    return 0;
}