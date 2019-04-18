//https://leetcode.com/problems/ugly-number/
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
    vector<int> uglynums {2,3,5};
    bool isUgly(int num) {
        if (num <=0)
            return false;
        if (1 == num)
            return true;
        bool found = false;
        while(num!=1) {
            found=false;
            for (auto & i:uglynums) {
                if (num % i == 0) {
                    num /= i;
                    found = true;
                }
            }
            if (!found && (num != 1)) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    auto s = Solution();
    int num;
    cin >> num;
    auto answer = s.isUgly(num);
    cout << answer << endl;
}