// Move Zeroes to end 
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;  // Pointer to track the position of the next non-zero element
        int n = nums.size();
        
        // Move non-zero elements to the front
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                // Swap only when necessary (i != j)
                if (i != j) {
                    swap(nums[i], nums[j]);
                }
                j++;  // Increment j after placing the non-zero element
            }
        }
    }
};
