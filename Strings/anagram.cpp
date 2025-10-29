
//optimal TC-O(n) SC-O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        vector<int> count(26, 0); //lowecase ke liye

        for (int i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;   // s[0] = r  then a= 97 then r-a=17 so 17 index par r hh to vo aaya ek baar count increase
            count[t[i] - 'a']--;
        }


//agar frequency same in both s & t to count = 0 
        for (int x : count) {
            if (x != 0) return false;
        }
        return true;
    }
};




/*brute - tc- O(n logn) for sorting
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
*/

/*better
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> freq;

        // Count frequency of each char in s
        for (char c : s) {
            freq[c]++;
        }

        // Subtract frequency using t
        for (char c : t) {
            freq[c]--;
            if (freq[c] < 0) return false; // more chars in t than s
        }

        // If all counts are zero → it's an anagram
        return true;
    }
};

*/