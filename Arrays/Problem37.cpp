





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        // Merge two sorted halves
        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            } else {
                temp.push_back(nums[right++]);
            }
        }

        // Remaining elements of left half
        while (left <= mid) temp.push_back(nums[left++]);

        // Remaining elements of right half
        while (right <= high) temp.push_back(nums[right++]);

        // Copy sorted elements back to original array
        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }

    int countPairs(vector<int>& nums, int low, int mid, int high) {
        int right = mid + 1;
        int cnt = 0;

        // Count reverse pairs
        for (int i = low; i <= mid; i++) {
            while (right <= high && (long long)nums[i] > 2LL * nums[right])
                right++;
            cnt += (right - (mid + 1));
        }
        return cnt;
    }

    int mergeSort(vector<int>& nums, int low, int high) {
        int cnt = 0;
        if (low >= high) return cnt;

        int mid = (low + high) / 2;
        cnt += mergeSort(nums, low, mid);        // left half
        cnt += mergeSort(nums, mid + 1, high);   // right half
        cnt += countPairs(nums, low, mid, high); // count reverse pairs
        merge(nums, low, mid, high);             // merge both halves

        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};


//TC - O(2n logn) 
//SC - O(n)