//optimal TC-O(n)  SC-O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> val = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int total = 0, prev = 0;

        for (int i = s.size() - 1; i >= 0; i--) {
            int curr = val[s[i]];
            if (curr < prev)
                total -= curr;
            else
                total += curr;
            prev = curr;
        }
        return total;
    }
};


/*brute
same tc and sc as optimal 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> val = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int n = s.size();
        int total = 0;

        for (int i = 0; i < n; i++) {
            if (i + 1 < n && val[s[i]] < val[s[i + 1]])
                total -= val[s[i]]; // subtract if smaller before larger
            else
                total += val[s[i]]; // else add normally
        }

        return total;
    }
};
*/