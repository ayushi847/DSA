
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            // if mid points to the target
            if (nums[mid] == target) return mid;

            // if left half is sorted
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target <= nums[mid]) {
                    // target lies in the left half
                    high = mid - 1;
                } else {
                    // target lies in the right half
                    low = mid + 1;
                }
            }
            else { // right half is sorted
                if (nums[mid] <= target && target <= nums[high]) {
                    // target lies in the right half
                    low = mid + 1;
                } else {
                    // target lies in the left half
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};
