class Solution {
public:
    int reverse(int x) {
        bool neg = x > 0?false:true;
        unsigned int uold = x;
        if (neg)
            uold = -x;
        unsigned n = 0;
        unsigned int cutoff = UINT32_MAX /10 + 1;
        vector<int> nums;
        while(uold > 0) {
            nums.push_back(uold % 10);
            uold /= 10;
        }
        for (auto i: nums) {
            if (n > cutoff) {
                return 0;
            }
            n *=10;
            unsigned int n1 = n + i;
            if (n1 < n || n > UINT32_MAX) {
                return 0;
            }
            n += i;
        }
        if (neg) {
            if (n > INT32_MIN)
                return 0;
            return -n;
        }
        if (n > INT32_MAX) {
            return 0;
        }
        return n;
    }
};
