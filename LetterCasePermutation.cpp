#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    vector<string> answer;
    vector<string> letterCasePermutation(string S) {
        backtrack(S, 0);
        return answer;
    }
    void backtrack(string &s, int i) {
        if (i == s.size()) {
            answer.push_back(s);
            return;
        }
        backtrack(s, i+1);
        if (isalpha(s[i])) {
            s[i] ^= (1 << 5);
            backtrack(s, i+1);
        }
        
    }
};

int main() {
 auto s = Solution();
 auto answer = s.letterCasePermutation("a1b2");
 for (auto &s:answer)
     cout << s << endl;
}