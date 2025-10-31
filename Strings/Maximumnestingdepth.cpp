#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
          int currDepth=0 , maxDepth=0;

          for(char c: s) {
                 if(c == '(')  {
                        currDepth++;
                        maxDepth = max(maxDepth,currDepth);
                 }   else if (c == ')') {
                        currDepth--;
                 }
          }
          return maxDepth;
    }
};

//TC- O(n) SC-O(1)

/*
brute
class Solution {
public:
    int maxDepth(string s) {
        int maxDepth = 0;

        for (int i = 0; i < s.size(); i++) {
            int curr = 0;
            for (int j = 0; j <= i; j++) {
                if (s[j] == '(') curr++;
                else if (s[j] == ')') curr--;
            }
            maxDepth = max(maxDepth, curr);
        }
        return maxDepth;
    }
};
Time: O(n²) (nested loops)

Space: O(1)*/



/*better
class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int maxDepth = 0;

        for (char c : s) {
            if (c == '(') {
                st.push(c);
                maxDepth = max(maxDepth, (int)st.size());
            } else if (c == ')') {
                st.pop();
            }
        }
        return maxDepth;
    }
};
Time: O(n) — single pass

Space: O(n) — for stack in worst case (all '(')*/