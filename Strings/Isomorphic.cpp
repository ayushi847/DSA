//optimal TC-O(n)  SC-O(1)
#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t) {
    if (s.length() != t.length()) return false;

    vector<int> lastS(256, -1);
    vector<int> lastT(256, -1);

    for (int i = 0; i < s.length(); i++) {
        if (lastS[s[i]] != lastT[t[i]])
            return false;

        lastS[s[i]] = i;
        lastT[t[i]] = i;
    }
    return true;
}



/*better
         #include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t) {
    if (s.length() != t.length()) return false;

    unordered_map<char, char> mp;
    unordered_set<char> mapped;

    for (int i = 0; i < s.length(); i++) {
        char c1 = s[i], c2 = t[i];

        if (mp.count(c1)) {
            if (mp[c1] != c2)
                return false; // mapping doesn't match
        } else {
            if (mapped.count(c2))
                return false; // c2 already mapped by someone else
            mp[c1] = c2;
            mapped.insert(c2);
        }
    }
    return true;
}

Time Complexity:

O(n)

💾 Space Complexity:

O(2n) ≈ O(n)

*/



/*brute
#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t) {
    if (s.length() != t.length()) return false;

    vector<char> mapping(256, 0); // store s->t mapping
    vector<bool> used(256, false); // track which chars in t are already used

    for (int i = 0; i < s.length(); i++) {
        char c1 = s[i], c2 = t[i];

        if (mapping[c1] == 0) { // not yet mapped
            // check if c2 is already used
            if (used[c2]) return false;
            mapping[c1] = c2;
            used[c2] = true;
        } else if (mapping[c1] != c2) {
            return false;
        }
    }
    return true;
}

Time Complexity:

O(n) for traversal

O(1) for mapping (since ASCII size is constant)
👉 O(n) overall

💾 Space Complexity:

O(256 + 256) = O(1) (constant)
*/