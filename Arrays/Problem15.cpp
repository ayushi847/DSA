



#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = nums[0];
        int start = 0, ansStart = 0, ansEnd = 0; 

        for (int i = 0; i < nums.size(); i++) {
            if (sum == 0) start = i;

            sum += nums[i];

            if (sum > maxi) {
                maxi = sum;          
                ansStart = start;  
                ansEnd = i;           
            }

            if (sum < 0) {
                sum = 0; 
            }
        }

        return maxi; 
    }
};
