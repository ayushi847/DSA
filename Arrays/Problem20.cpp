
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
        vector<int> ans;
        int maxi = INT_MIN;
        int n = nums.size();

        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] > maxi) {
                ans.push_back(nums[i]);
                maxi = nums[i];
            } else {
                maxi = max(maxi, nums[i]);
            }
        }

        reverse(ans.begin(), ans.end()); // Fix: reverse instead of sort
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    vector<int> result = obj.leaders(nums);

    cout << "Leaders in the array: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
