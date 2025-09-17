
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotateArrayByOne(vector<int>& nums) {
        int n = nums.size();  // 🔹 yahi missing tha
        if (n == 0) return;

        int temp = nums[0];
        for (int i = 1; i < n; i++) {
            nums[i - 1] = nums[i];
        }
        nums[n - 1] = temp;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};

    sol.rotateArrayByOne(nums);

    for (int x : nums) {
        cout << x << " ";
    }
    return 0;
}
