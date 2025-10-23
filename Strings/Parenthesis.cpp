
#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int depth = 0;

        for (int i = 0 ; i < s.size() ; i++) {
            if (s[i] == '(') {
                if (depth > 0) result += s[i];
                depth++;
            } else {
                depth--;
                if (depth > 0) result += s[i];
            }
        }

        return result;
    }
};
