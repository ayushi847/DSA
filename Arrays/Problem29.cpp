
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLen(vector<int>& arr) {
        map<int, int> mpp;
        int maxi = 0;
        int sum = 0;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (sum == 0) {
                maxi = i + 1;
            } 
            else {
                if (mpp.find(sum) != mpp.end()) {
                    maxi = max(maxi, i - mpp[sum]);
                } 
                else {
                    mpp[sum] = i;
                }
            }
        }
        return maxi;
    }
};

int main() {
    Solution obj;
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = obj.maxLen(arr);
    cout << "\nLength of longest subarray with sum 0: " << ans << endl;

    return 0;
}
