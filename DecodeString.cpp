//https://leetcode.com/problems/decode-string/


#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<string>
#include<map>

using namespace std;


// add * op to string
template<typename Char, typename Traits, typename Allocator>
std::basic_string<Char, Traits, Allocator> operator *
(const std::basic_string<Char, Traits, Allocator> s, size_t n)
{
   std::basic_string<Char, Traits, Allocator> tmp;
   for (size_t i = 0; i < n; ++i)
   {
      tmp += s;
   }
   return tmp;
}

template<typename Char, typename Traits, typename Allocator>
std::basic_string<Char, Traits, Allocator> operator *
(size_t n, const std::basic_string<Char, Traits, Allocator>& s)
{
   return s * n;
}

class Solution {
public:
    int cursor;
    string input;
    string ans;

    string parse_pattern(string s) {
        //string digits;
        int n=0;
        string spattern;
        while(cursor<s.size()) {
            // start
            while (cursor < s.length() && isdigit(s[cursor]))
                    n = n * 10 + s[cursor++] - '0';
            if (s[cursor] == '[') {
                cursor++;//start pattern string eat [
                while( s[cursor] != ']' && cursor<s.size())  {
                    if (isdigit(s[cursor]))
                        spattern += parse_pattern(s);
                    if (isalpha(s[cursor])) {
                        spattern.push_back(s[cursor]);
                        cursor++;
                    }
                }
                //spattern = spattern * atoi( digits.c_str());
                spattern = spattern * n;
                cursor++; // eat ]
                return spattern;
            }
        }
        return spattern;
    }
    

    string decodeString(string s) {
        if (s.size() == 0)
            return "";
        cursor = 0;
        input = s;
        string ans;
        while(cursor<s.size()) {
            if (isdigit(s[cursor])) {
                ans += parse_pattern(s);
            } else {
                ans += string(1, s[cursor]);
                cursor++;
            }
        }
        return ans;
    }
};

int main() {
    auto s = Solution();
    //auto ans = s.decodeString("2[abc]3[cd]ef"); //"abcabccdcdcdef"
    // "3[a2[c]]" "accaccacc"
    //cout << ans << endl;
    // auto ans = s.decodeString("3[a2[c]]"); //"accaccacc"
    // cout << ans << endl;
    auto ans = s.decodeString("2[ab3[cd]]4[xy]");
    cout << ans << endl;
    
    return 0;
}
