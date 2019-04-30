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

class Solutionold {
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

// min(1 * (2,3,5))
// min( (1,2) * (2,3,5) )

class Solution {
public:
    int nthUglyNumber(int n) {
        if (1 == n)
            return 1;
        int p1=0, p2=0, p3=0;
        vector<int> k(n);
        k[0] = 1;
        for(int i =1;i<n;i++) {
            k[i] = min(k[p1]*2, min(k[p2]*3, k[p3]*5));
            if (k[i] == k[p1]*2) p1++;
            if (k[i] == k[p2]*3) p2++;
            if (k[i] == k[p3]*5) p3++;
        }
        return k[n-1];
    }
};

int main() {
    auto s = Solution();
    auto answer = s.nthUglyNumber(10);
    cout << answer << endl;
}