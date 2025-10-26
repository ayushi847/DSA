
//Optimal 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.size() - 1);
                if (prefix.empty()) return "";
            }
        }
        return prefix;
    }
};  

/*O(N × M) — each comparison may shrink prefix   &    SC-   O(1)  */


//Brute 
/*#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        string first = strs[0];

        for (int i = 0; i < first.size(); i++) {
            char ch = first[i];
            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].size() || strs[j][i] != ch)
                    return ans;
            }
            ans += ch;
        }
        return ans;
    }
};  */


//Time Complexity:
/*
O(N × M)
(N = no. of strings, M = length of smallest string)

 Space Complexity:

O(1)*/



/*  Better solution 
   #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string first = strs[0], last = strs.back();
        string ans = "";

        for (int i = 0; i < first.size(); i++) {
            if (i < last.size() && first[i] == last[i])
                ans += first[i];
            else
                break;
        }
        return ans;
    }
};    

TC - Sorting → O(N log N)

Comparing first and last string → O(M)
👉 Total: O(N log N + M), where
N = number of strings, M = min string length

SC- O(1)
*/