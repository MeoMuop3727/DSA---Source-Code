#pragma once
#include <vector>
#include <climits>
#include <stack>

namespace add_tools {
    int lrh(std::vector<int> &heights) {
        
        /*
            Problem: LARGEST RECTANGLE IN HISTOGRAM (LRH)
            Link video: https://youtu.be/zx5Sw9130L0?si=YqaOcR8om1qeWJfA
        */

        // int rs = INT_MIN; // Base case, Result
        // int n = heights.size(); // Size

        // for (int i = 0; i < n; i++) {
        //     int r = i, l = i; // Right, Left
            
        //     // Expand to right
        //     // If the right is still in allowed range
        //     // And the value at right must be bigger than i
        //     // For example,
        //     // 5 (i = 2) --> 6 (r = 3) => true => right++
        //     // 5 (i = 2) --> 2 (r = 4) => flase => end;
        //     while (r < n - 1 && heights[i] <= heights[r + 1]) r++;

        //     // Expand to left
        //     // If left is still huger than 0
        //     // And the value at left must be bigger than i
        //     // For example,
        //     // 5 (i = 2) --> 1 (l = 1) => flase => end;
        //     // 1 (i = 1) --> 2 (l = 0) => true => left++
        //     while (l > 0 && heights[i] <= heights[l - 1]) l--;

        //     // The weight = right - left + 1
        //     // The height = heights[i]
        //     // The size = weight * height
        //     // Compare the current result and the temp result
        //     // Choose the maximum
        //     rs = std::max(rs, heights[i] * (r - l + 1));
        // }

        // return rs;

        /*
            =====================================================
            IMPROVE ALGORITHM FIND MAXIMUM RECTANGLE IN HISTOGRAM
            =====================================================
        */
        std::stack<int> s;
        int n = heights.size();

        int maxRect = INT_MIN; // Base case

        // Traversal all elements in heights
        for (int i = 0; i <= n; i++) {
            // If i is overflow
            // This means i is bigger than size of height
            // Assign it by 0 to can traversal remain elements in stack
            // Else
            // Assign the height at i
            int height_i = (i >= n) ? 0 : heights[i];

            // If stack is not empty
            // And the height of previous element is smaller than the current
            // This means we can not expand continuely
            // Get the index top
            // Right = i
            // Left = s.top() after s.pop() the previous element in stack
            // If stack empty, assign -1 
            while (!s.empty() && height_i < heights[s.top()]) {
                int top = s.top(); s.pop(); // The index of element
                int right = i; 
                int left = (s.empty()) ? -1 : s.top(); 

                // Calculate the maxRect
                // Current height * (right - left - 1), with "right - left - 1 = width"
                // Compare previous maxRect, if current maxRect is bigger
                // Get it
                maxRect = std::max(maxRect, heights[top] * (right - left - 1));
            }

            // Else
            // This means we can expand
            // Or stack is empty
            // Push new index of element
            s.push(i);
        }

        // Return maximum rectangle
        return maxRect;
    }
}