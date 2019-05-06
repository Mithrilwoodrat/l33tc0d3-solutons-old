// https://leetcode.com/problems/daily-temperatures/
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
    void debug_stack(list<int> L) {
        cout << "stack :";
        for (auto &i: L) {
            cout << i << " ";
        }
        cout << endl;
    }
    // 反向遍历数组，使用 stack 使其保持升序排练，新遍历的元素与栈顶元素索引的差即为该天之后多少天天气会变热
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> answer(T.size());
        answer.assign(T.size(), 0);
        if (T.size() == 0 || T.size() == 1)
            return answer;
        list<int> stack;
        for (int i=T.size()-1;i>=0;i--) {
            while (!stack.empty() && T[i] >= T[stack.back()]) {
                stack.pop_back();
            }
            if (!stack.empty()) {
                answer[i] = stack.back() - i;         
            }
            stack.push_back(i);
            //cout << "i: " << i << endl;
            //debug_stack(stack);
        }
        return answer;
    }
};

int main() {
    auto s = Solution();
    vector<int> nums {73, 74, 75, 71, 69, 72, 76, 73};
    // [1, 1, 4, 2, 1, 1, 0, 0]
    auto answer = s.dailyTemperatures(nums);
    for (auto &i : answer)
        cout << i << endl;
}
