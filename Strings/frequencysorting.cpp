

//Optimal - bucket sorting TC-O(n)   SC-O(n) -bucket and result 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;

        int n = s.size();
        vector<string> bucket(n + 1, "");

        // Fill buckets
        for (auto& it : freq) {
            char ch = it.first;
            int count = it.second;
            bucket[count] += string(count, ch);
        }

        // Build result from highest freq to lowest
        string result = "";
        for (int i = n; i >= 0; i--) {
            result += bucket[i];
        }

        return result;
    }
};

int main() {
    Solution sol;
    string s = "tree";
    cout << sol.frequencySort(s) << endl;
    return 0;
}


/*  brute
   class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;

        // Sort manually using nested loops (brute O(n²))
        string ans = s;
        for (int i = 0; i < ans.size(); i++) {
            for (int j = i + 1; j < ans.size(); j++) {
                if (freq[ans[j]] > freq[ans[i]]) {
                    swap(ans[i], ans[j]);
                }
            }
        }
        return ans;
    }
};
⏱️ Time Complexity:

O(n²) — because of nested loops
✅ Works but not efficient.


🔍 Space Usage Breakdown
Component	Description	Space
unordered_map<char, int> freq	Stores frequency of each unique character
	O(k) where k = number of unique characters
string ans = s	Copy of input string for sorting	O(n)
Loop variables (i, j, etc.)	Constant space	O(1)


final O(n)
*/



/*better  -sort + map

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;

        sort(s.begin(), s.end(), [&](char a, char b) {
            if (freq[a] == freq[b]) return a < b; // optional (lexicographically)
            return freq[a] > freq[b];
        });

        return s;
    }
};

Type	Complexity	Reason
Time Complexity  	O(n log n)	Sorting based on frequency
Space Complexity	O(log n)	Due to recursion stack of sort() + small map

 
*/