




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int countSub(vector<int> &a, int maxSum) {
        int n = a.size();
        int no_sub = 1;
        long long curr = 0;

        for (int i = 0; i < n; i++) {
            if (curr + a[i] <= maxSum) {
                curr += a[i];    
            } else {
                no_sub++;           
                curr = a[i];
            }
        }
        return no_sub;
    }

    int splitArray(vector<int>& nums, int k) {

        int low = *max_element(nums.begin(), nums.end());   // max(arr)
        int high = accumulate(nums.begin(), nums.end(), 0); // sum(arr)

        while (low <= high) {
            int mid = (low + high) / 2;   // (low + high)/2
            int no_sub = countSub(nums, mid);

            if (no_sub > k) {
                low = mid + 1;   // low = mid + 1
            } else {
                high = mid - 1;  // high = mid - 1
            }
        }
        return low;               // return low
    }
};
