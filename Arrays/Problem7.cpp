#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        int i = 0;
        int j = 0;

        vector<int> unionArr;

        while (i < n1 && j < n2) {
            if (nums1[i] <= nums2[j]) {
                if (unionArr.size() == 0 || unionArr.back() != nums1[i]) {
                    unionArr.push_back(nums1[i]);
                }
                i++;
            }
            else {
                if (unionArr.size() == 0 || unionArr.back() != nums2[j]) {
                    unionArr.push_back(nums2[j]);
                }
                j++;
            }
        }

        while (j < n2) {
            if (unionArr.size() == 0 || unionArr.back() != nums2[j]) {
                unionArr.push_back(nums2[j]);
            }
            j++;
        }

        while (i < n1) {
            if (unionArr.size() == 0 || unionArr.back() != nums1[i]) {
                unionArr.push_back(nums1[i]);
            }
            i++;
        }

        return unionArr;
    }
};

int main() {
    Solution sol;

    // ✅ Input arrays (already sorted)
    vector<int> nums1 = {1, 2, 2, 3, 5};
    vector<int> nums2 = {2, 3, 4, 6};

    // ✅ Call unionArray
    vector<int> result = sol.unionArray(nums1, nums2);

    // ✅ Print the result
    cout << "Union of the arrays: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
