
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findTargetIndex(vector<int>& nums, int target) {
        // Loop through the array
        for (int i = 0; i < nums.size(); i++) {
            // If the current element matches the target, return its index
            if (nums[i] == target) {
                return i;
            }
        }
        // If target is not found, return -1
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 3, 4, 5, 3};

    // Example: Searching for target 3
    int target = 3;
    int index = sol.findTargetIndex(nums, target);

    cout << "Index of target " << target << " is: " << index << endl;

    return 0;
}
