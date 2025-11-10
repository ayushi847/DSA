
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int floorSqrt(int n) {
        int low = 1, high = n;
        
        while (low <= high) {
            long long mid = (low + high) / 2;
            long long val = mid * mid;

            if (val == n)
                return mid;
            else if (val < n)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return high; // 'high' will store floor(sqrt(n))
    }
};

int main() {
    Solution obj;
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Floor square root of " << n << " is " << obj.floorSqrt(n);
    return 0;
}
