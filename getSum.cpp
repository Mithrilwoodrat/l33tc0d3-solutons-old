// Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

// https://leetcode.com/problems/sum-of-two-integers/discuss/84278/A-summary:-how-to-use-bit-manipulation-to-solve-problems-easily-and-efficiently

#include <iostream>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        if (b == 0)
            return a;
        cout << a << " " << b << endl;
        cout << (a^b) << " " << (a&b) << endl;
        return getSum(a^b, (a&b)<<1);
    }
};

int main() {
    auto s = Solution();
    auto answer = s.getSum(1, 2);
    cout << answer << endl;
}