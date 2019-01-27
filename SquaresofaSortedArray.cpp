#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    long power(int x) {
        if (x < 0) {
            x = - x;
        }
        return x * x;
    }
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> result;
        for (auto n : A) {
            result.push_back(power(n));
        }
        sort(result.begin(), result.end());
        return result;
    }
};