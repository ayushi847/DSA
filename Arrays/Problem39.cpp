
/* Brute Force Solution -- O(N^2)   

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int width = j - i;
                int h = min(height[i], height[j]);
                int area = width * h;
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};   */





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxArea = 0;

        while (left < right) {
            int width = right - left;
            int h = min(height[left], height[right]);
            int area = width * h;
            maxArea = max(maxArea, area);

            // Move the smaller height pointer inward
            if (height[left] < height[right])
                left++;
            else
                right--;
        }

        return maxArea;
    }
};   