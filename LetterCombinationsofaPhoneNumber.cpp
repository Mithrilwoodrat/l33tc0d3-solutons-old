#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<map>
#include<string>

using namespace std;

class Solution {
public:
    map<int, vector<char>> keyboard;
    vector<string> answer;
    void init_keyboard() {
        keyboard[2] = {'a','b','c'};
        keyboard[3] = {'d','e','f'};
        keyboard[4] = {'g','h','i'};
        keyboard[5] = {'j','k','l'};
        keyboard[6] = {'m','n','o'};
        keyboard[7] = {'p','q','r','s'};
        keyboard[8] = {'t','u','v'};
        keyboard[9] = {'w','x','y','z'};
    }
    vector<string> letterCombinations(string digits) {
        init_keyboard();
        // for (auto & it : keyboard) {
            // cout << it.first << endl;
            // for (auto & c : it.second)
                // cout << c << endl;
        // }
        string ans = "";
        backtrack(digits, 0, ans);
        return answer;
    }
    void backtrack(const string &digits, int index, string& ans) {
        if (index==digits.size()){
            answer.push_back(ans);
            return;
        }
        int digit = digits[index] - '0';
        for(int i =0; i < keyboard[digit].size(); i++) {
            ans.push_back(keyboard[digit][i]);
            backtrack(digits, index + 1, ans);
            ans.pop_back();
        }
    }
};

int main() {
 auto s = Solution();
 auto answer = s.letterCombinations("23");
 for (auto &s:answer)
     cout << s << endl;
}