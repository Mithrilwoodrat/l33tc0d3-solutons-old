#include<string>
#include<iostream>
#include<vector>

using namespace std;

//https://leetcode.com/problems/palindromic-substrings/
class Solution {
public:
    void debug_dp(vector<vector<int> > &dp) {
        for (int i=0;i<dp.size();i++) {
            for (int j=0;j<dp.size();j++)
            cout << "dp i:" << i << ",j:" << j << "=" << dp[i][j] << endl;
        }
        cout << endl;
    }
    string longestPalindrome(string s) {
        size_t length = s.size();
        if (length == 0)
            return "";
        vector<vector<int> > dp(s.size());
        int i,j;
        // init 2d dp array with 0
        for (i=0;i<s.size();i++) {
            dp[i].assign(s.size(), 0);
            dp[i][i] = 1;
        }
        int max = 1;
        string answer = s.substr(0, 1);
        for (int i=0;i<length;i++) {
            for (int j=0;j<=i;j++) {
                //cout << "i: " << i << "j: " << j << "\t" << s.substr(j, i-j+1) << endl;
                if (i==j) {
                    continue;
                } else if (j+1 == i && s[j]==s[i]) {
                    dp[i][j] = 1;
                    if (i-j+1 > max) {
                        max = i-j+1;
                        answer = s.substr(j, i-j+1);
                    }
                } else if ( dp[i-1][j+1] == 1 && s[j]==s[i]) {
                    dp[i][j] = 1;
                    if (i-j+1 > max) {
                        max = i-j+1;
                        answer = s.substr(j, i-j+1);
                    }
                }
                //debug_dp(dp);
            }
        }
        return answer;
    }
};

int main() {
    auto s = Solution();
    auto answer = s.longestPalindrome("babad");
    cout << "answer: "<< answer << endl;

    answer = s.longestPalindrome("cbbd");
    cout << answer << endl;
    return 0;
}