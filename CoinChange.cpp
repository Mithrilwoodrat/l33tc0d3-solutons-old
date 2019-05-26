// https://leetcode.com/problems/coin-change/
#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> coins;
    int amount;
    vector<int> lefts;
    int coinChange(vector<int>& coins, int amount) {
        this->coins = coins;
        this->amount = amount;
        vector<int> lefts(amount);
        lefts.assign(lefts.size(), 0);
        return traceback(amount, lefts);
    }
    int traceback(int left, vector<int> &lefts) {
        cout << left << "\t" << lefts[left-1] <<endl;
        if (left == 0) {
            return 0;
        } else if (left < 0) {
            return -1 ;
        } else if (lefts[left-1] != 0) {
            return lefts[left-1];
        }
        int min = -1;
        for(int i=0;i<coins.size();i++) {
            int ans = traceback(left-coins[i], lefts);
            if (ans >=0 && (ans < min || min==-1))
                min = ans + 1;
        }
        if (min == -1) {
            lefts[left-1] = -1;
        } else {
            lefts[left-1] = min;
        }
        return lefts[left-1];
    }
};

int main() {
    auto s = Solution();
    vector<int> nums {1,2,5};
    auto answer = s.coinChange(nums, 11);
    cout << answer << endl;
    //[474,83,404,3]
    //264
    vector<int> nums2 {474,83,404,3};
    auto answer2 = s.coinChange(nums2, 264);
    cout << answer2 << endl;
}