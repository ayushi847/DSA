
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> mp;
    vector<int> result;

    
    for (int num : nums1) {
        mp[num] = 1;  
    }

    
    for (int num : nums2) {
        if (mp[num] == 1) {
            result.push_back(num);
            mp[num] = 0;  
        }
    }

    return result;
}

int main() {
    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {9, 4, 9, 8, 4};
    vector<int> ans = intersection(nums1, nums2);

    cout << "[ ";
    for (int num : ans) cout << num << " ";
    cout << "]";
}  