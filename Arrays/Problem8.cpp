#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& a) {
        int xor1 = 0, xor2 = 0;
        int N = a.size();   // ab N array ke size ke barabar hai

        for (int i = 0; i < N; i++) {
            xor2 ^= a[i];       // array ke elements ka XOR
            xor1 ^= (i + 1);    // 1..N tak ka XOR
        }

        return (xor1 ^ xor2);   // dono ka XOR = missing number
    }
};