#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0 ,  n = s.size() ,sign = 1;
        long result = 0;
        

        while(i < n &&  s[i] == ' ') i++;

        if(i < n &&  (s[i] == '+' ||  s[i] == '-')) {
                 sign = (s[i] == '-') ? -1 : 1;
                 i++;
        }

        while(i < n && isdigit(s[i])) {
                  int digit = s[i] - '0';

                  if(result > (INT_MAX - digit) / 10) {
                       return sign == 1 ? INT_MAX : INT_MIN;
                  }

                  result = result * 10 + digit;
                  i++;
        }
         return (int)(result * sign);
    }
};

/*✅ Time Complexity:

O(n) — traverse each character once

✅ Space Complexity:

O(1) — only variables used*/ 

/*brute
class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();

        // Step 1: ignore spaces
        while (i < n && s[i] == ' ') i++;

        // Step 2: check sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // Step 3: extract digits
        string numStr = "";
        while (i < n && isdigit(s[i])) {
            numStr += s[i];
            i++;
        }

        if (numStr.empty()) return 0;

        // Step 4: convert and clamp
        long num = stol(numStr) * sign;
        if (num < INT_MIN) return INT_MIN;
        if (num > INT_MAX) return INT_MAX;
        return num;
    }
};
✅ Time Complexity:

O(n) → traverse whole string once

✅ Space Complexity:

O(n) → extra numStr used*/


/*better
class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        long result = 0;
        int sign = 1;

        // Skip spaces
        while (i < n && s[i] == ' ') i++;

        // Handle sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Build number
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            
            // Overflow handling
            if (result * sign >= INT_MAX) return INT_MAX;
            if (result * sign <= INT_MIN) return INT_MIN;

            i++;
        }

        return result * sign;
    }
};
✅ Time Complexity:

O(n) — single traversal

✅ Space Complexity:

O(1) — no extra space used*/