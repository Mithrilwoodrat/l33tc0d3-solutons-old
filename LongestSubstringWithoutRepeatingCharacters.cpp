#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0)
            return 0;
        int i, j;
        char c;
        string tmp;
        int cnt = 0, result = 0;
        for (i=0; i < s.length(); i++) {
            for (j = i; j < s.length(); j++) {
                c = s[j];
                if ( tmp.find(c) == string::npos ) {
                    cnt ++;
                    tmp += c;
                } else {
                    break;
                }
            }
            if (cnt > result) {
                //cout << tmp << endl;
                result = cnt;
            }
            tmp = "";
            cnt = 0;
        }
        return result;
    }
};

int main() {
    auto s = Solution();
    auto answer = s.lengthOfLongestSubstring("dvdf");
    cout << answer << endl;

    answer = s.lengthOfLongestSubstring("pwwkew");
    cout << answer << endl;
}