
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end()); // greed factor
        sort(s.begin(), s.end()); // cookie sizes

        int i = 0; //children
        int j = 0; // cookies  

        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                // current cookie satisfies child
                i++;
            }
            // move to next cookie
            j++;
        }

        return i; // number of content children
    }
};


//Tc- O(nlogm + mlogn)
//sc - O(1)


//Brute 

// Tc- O(n*m)
//sc - O(1)


int findContentChildren(vector<int>& g, vector<int>& s) {
    int cnt = 0;
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    for (int i = 0; i < g.size(); i++) {
        for (int j = 0; j < s.size(); j++) {
            if (s[j] >= g[i]) {
                cnt++;
                s[j] = -1; // mark cookie as used
                break;
            }
        }
    }
    return cnt;
}
