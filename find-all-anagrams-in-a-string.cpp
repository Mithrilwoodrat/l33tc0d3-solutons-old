//https://leetcode.com/problems/find-all-anagrams-in-a-string/


#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<map>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams_old(string s, string p) {
        map<char, int> anagrams;
        vector<int> ans;
        int i,j;
        for (i =0;i<p.size();i++) {
            if (anagrams.count(p[i])) {
                anagrams[p[i]] += 1;
            } else
            {
                anagrams[p[i]] = 1;
            }
            
        }
        map<char, int> tmp;
        for (i=0;i<s.size();i++) {
            tmp.clear();
            //cout << "i: " << i << endl;
            if (anagrams.count(s[i])) {
	            for (j=i;(j<s.size())& ((j-i)<p.size());j++) {
		            if (anagrams.count(s[j])){
                        if (tmp.count(s[j]) ) {
                            tmp[s[j]] += 1;
                        } else {
                            tmp[s[j]] = 1;
                        }
                    }
                    //cout << tmp.size() << " , " << p.size() << endl;
                }
                //cout << tmp.size() << endl;

            }
            if (tmp == anagrams) {
                ans.push_back(i);
            }
        }
        return ans;
    }
    // siding window
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (p.size() > s.size()) {
            return ans;
        }
        vector<int> anagrams(26), tmp(26);

        int i,j;
        for (i =0;i<p.size();i++) {
            anagrams[p[i]-'a']++;
            tmp[s[i]-'a']++;
        }
        if (tmp == anagrams) {
            ans.push_back(0);
        }
        for (i=p.size();i<s.size();i++) {
            tmp[s[i]-'a']++; // 右边移动一位，对应字符+1
            tmp[s[i-p.size()]-'a']--; // 右边移动一位，移除的字符-1
            if (tmp == anagrams) {
                ans.push_back(i-p.size()+1);
            }
        }
        return ans;
    }
};

int main() {
    auto s = Solution();
    //s: "cbaebabacd" p: "abc"
    //[0, 6]

    auto ans = s.findAnagrams("cbaebabacd", "abc");

    //auto ans = s.findAnagrams("baa", "aa");
    for (auto &i:ans) {
        cout << i << "\t";
    }
    cout << endl;
    return 0;
}
