//https://leetcode.com/problems/maximal-square/
#include<iostream>
#include<stdio.h>
#include<vector>
#include<list>
#include<iterator>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows=0,columns=0;
        if (matrix.size() > 0) {
            rows = matrix.size();
        }
        if (rows && matrix[0].size()>0) {
            columns=matrix[0].size();
        }
        cout << rows << "," << columns << endl;
        vector<vector<int> > dp(rows+1);
        int i,j;
        // init 2d dp array with 0
        for (i=0;i<=rows;i++) {
            dp[i].assign(columns+1, 0);
        }
        int max_len =0;
        for(i=1;i<=rows;i++) {
            for(j=1;j<=columns;j++) {
                if (matrix[i-1][j-1] == '1'){
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                    cout << dp[i][j] << endl;
                    if (dp[i][j] > max_len)
                        max_len=dp[i][j];
                }
            }
        }
        return max_len*max_len;
    }
};

int main() {
    auto s = Solution();
    // 1 0 1 0 0  dp 1 0 1 0 0
    // 1 0 1 1 1     1 0 1 1 1
    // 1 1 1 1 1     1 1 1 2 2
    // 1 0 0 1 0     1 0 0 1 0
    vector<vector<char>> nums {{'1','0','1','0','0'},
                               {'1','1','1','1','1'},
                               {'1','1','1','1','1'},
                               {'1','1','1','1','1'}};
    for (int i=0;i<nums.size();i++) {
        for (int j=0;j<nums[i].size();j++) {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
    auto answer = s.maximalSquare(nums);
    cout << answer << endl;
}