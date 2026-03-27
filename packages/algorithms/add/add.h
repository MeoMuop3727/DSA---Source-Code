#pragma once
#include <vector>
#include <climits>

namespace add_tools {
    int lrh(std::vector<int> &histogram) {
        
        /*
            Problem: LARGEST RECTANGLE IN HISTOGRAM (LRH)
            Link video: https://youtu.be/zx5Sw9130L0?si=YqaOcR8om1qeWJfA
        */

        int rs = INT_MIN; // Base case, Result
        int n = histogram.size(); // Size

        for (int i = 0; i < n; i++) {
            int r = i, l = i; // Right, Left
            
            // Expand to right
            // If the right is still in allowed range
            // And the value at right must be bigger than i
            // For example,
            // 5 (i = 2) --> 6 (r = 3) => true => right++
            // 5 (i = 2) --> 2 (r = 4) => flase => end;
            while (r < n - 1 && histogram[i] <= histogram[r + 1]) r++;

            // Expand to left
            // If left is still huger than 0
            // And the value at left must be bigger than i
            // For example,
            // 5 (i = 2) --> 1 (l = 1) => flase => end;
            // 1 (i = 1) --> 2 (l = 0) => true => left++
            while (l > 0 && histogram[i] <= histogram[l - 1]) l--;

            // The weight = right - left + 1
            // The height = histogram[i]
            // The size = weight * height
            // Compare the current result and the temp result
            // Choose the maximum
            rs = std::max(rs, histogram[i] * (r - l + 1));
        }

        return rs;
    }
}