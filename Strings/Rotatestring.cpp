
//Optimal Approach (KMP / Rabin-Karp)
#include <bits/stdc++.h>
using namespace std;

bool rotateString(string s, string goal) {
    if (s.size() != goal.size()) return false;

    string doubled = s + s;
    return doubled.find(goal) != string::npos; // internally optimized
}
 
/*
Time Complexity:

O(n²) worst case (because find() may take O(n²) in naive search)

O(n) average with efficient substring search algorithms (like KMP used internally in find()).

💾 Space:

O(n) — extra space for s + s.
*/



/*better
   same AS optimal

*/

/*brute
#include <bits/stdc++.h>
using namespace std;

bool rotateString(string s, string goal) {
    if (s.size() != goal.size()) return false;

    for (int i = 0; i < s.size(); i++) {
        // Rotate: move first char to end
        char ch = s[0];
        s.erase(s.begin());
        s.push_back(ch);

        if (s == goal) return true;
    }
    return false;
}

O(n²) — Each rotation O(n), done n times.

O(1) space.

*/