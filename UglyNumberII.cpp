//https://leetcode.com/problems/ugly-number-ii/
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
    vector<int> uglynums {2,3,4,5,6,8,9,10,12};
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
    int nthUglyNumber(int n) {
        if (1 == n) {
            return 1;
        }
        if (n <= uglynums.size()+1) {
            return uglynums[n-2];
        }
        int cnt=10;
        for(int i=12;i++;) {
            if (isUgly(i)) {
                cnt++;
                if (cnt==n) {
                    return i;
                }
                uglynums.push_back(i);
            }
        }
        return 0;
    }
};

int main() {
    auto s = Solution();
    auto answer = s.nthUglyNumber(10);
    cout << answer << endl;
}