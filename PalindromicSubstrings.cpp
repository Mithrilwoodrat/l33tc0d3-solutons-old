#include<string>
#include<iostream>
#include<vector>

using namespace std;

//https://leetcode.com/problems/palindromic-substrings/
class Solution {
public:
    void debug_substrings(vector <string> substrings) {
        for (auto i : substrings) {
            cout << i << " , ";
        }
        cout << endl;

    }
    bool is_palindromic(string s) {
        string reverse;
        reverse.assign(s.rbegin(), s.rend());
        return s == reverse;
    }
    int countSubstrings(string s) {
        size_t length = s.length();
        if (length == 0)
            return 0;
        vector <string> substrings;
        int cnt = 0;
        string tmp;
        for (int i=0;i<length;i++) {
            cnt ++;
            substrings.push_back(string(1, s[i]));
            for (int j=0;j<i;j++) {
                tmp = s.substr(j, i-j+1);
                if (is_palindromic(tmp) ) {
                    substrings.push_back(tmp);
                    cnt ++;
                }
            }
            debug_substrings(substrings);
        }
        return cnt;
    }
};

int main() {
    auto s = Solution();
    auto answer = s.countSubstrings("abc");
    cout << answer << endl;

    answer = s.countSubstrings("aaa");
    cout << answer << endl;

}