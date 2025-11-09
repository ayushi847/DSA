#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int low = 0, high = n - 1;
        int ans = INT_MAX;

        while (low <= high) {
            int mid = (low + high) / 2;

            // If left part is sorted
            if (arr[low] <= arr[mid]) {
                ans = min(ans, arr[low]); // Minimum in left sorted part
                low = mid + 1;            // Move to right half
            } 
            else {
                ans = min(ans, arr[mid]); // Minimum in right sorted part
                high = mid - 1;           // Move to left half
            }
        }

        return ans;
    }
};
