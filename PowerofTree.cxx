class Solution {
public:
    bool isPowerOfThree(int n) {
        while(n>0) {
            if (n % 3 == 0) {
                n /= 3;
            }
            else if (n == 1) {
                return true;
            }
            else {
                return false;
            }
        }
        if (n == 1) {
            return true;
        }
        return false;
    }
};
