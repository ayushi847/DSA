

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, long long k) {
        int left = 0, right = 0;
        long long sum = nums[0];
        int maxLen = 0;
        int n = nums.size();

        // Edge case: If the array is empty, return 0
        if (n == 0) return 0;

        while (right < n) {
            // Shrink the window when the sum exceeds k
            while (left <= right && sum > k) {
                sum -= nums[left];  // Remove the element at 'left'
                left++;
            }

            // If the sum matches k, update the maximum length
            if (sum == k) {
                maxLen = max(maxLen, right - left + 1);
            }

            // Expand the window by moving the right pointer
            right++;
            if (right < n) {
                sum += nums[right];  // Add the element at 'right'
            }
        }

        return maxLen;
    }
};
