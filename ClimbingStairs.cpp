//https://leetcode.com/problems/climbing-stairs/
#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<numeric>
#include<list>
#include<map>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n < 0)
            return 0;
        if (n==0)
            return 1;
        return climbStairs(n-1) + climbStairs(n-2);
    }
};

int main() {
    auto s = Solution();
    auto answer = s.climbStairs(4);
    cout << answer << endl;
}