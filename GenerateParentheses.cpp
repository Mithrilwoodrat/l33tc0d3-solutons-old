#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    vector<string> answer;
    vector<string> generateParenthesis(int n) {
        string ans = "";
        backtrack(ans, n, 0, 0);
        return answer;
    }
    void backtrack(string ans, int n, int left, int right) {
        if (right == n) {
            answer.push_back(ans);
            return;
        }
        if (left < n) {
            backtrack(ans + '(', n, left + 1,  right);
        }
        if (right < left ) {
            backtrack(ans + ')', n,  left, right + 1);
        }
    }
};

int main() {
 auto s = Solution();
 auto answer = s.generateParenthesis(3);
 for (auto &s:answer)
     cout << s << endl;
}