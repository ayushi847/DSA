
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int n = nums.size();         // FIXED: define 'n'
        for (int j = 1; j < n; j++) { // FIXED: declare 'j' properly, start from 1
            if (nums[j] != nums[i]) { // FIXED: use 'nums' instead of 'arr'
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};
