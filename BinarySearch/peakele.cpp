


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int low = 0, high = m - 1;   // binary search on columns

        while (low <= high) {
            int mid = (low + high) / 2;

            // find max element in this column
            int row = 0;
            for (int i = 1; i < n; i++) {
                if (mat[i][mid] > mat[row][mid])
                    row = i;
            }

            int left  = (mid - 1 >= 0 ? mat[row][mid - 1] : -1);
            int right = (mid + 1 < m ? mat[row][mid + 1] : -1);

            // check if this is the peak
            if (mat[row][mid] > left && mat[row][mid] > right)
                return {row, mid};

            // move left
            else if (left > mat[row][mid])
                high = mid - 1;

            // move right
            else
                low = mid + 1;
        }

        return {-1, -1};
    }
};
