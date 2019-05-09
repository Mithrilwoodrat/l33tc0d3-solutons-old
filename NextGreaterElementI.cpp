//https://leetcode.com/problems/next-greater-element-i/#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
#include<stack>
#include<map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stack;
        map<int, int> map;
        vector<int> answer;
        for (int i=0;i<nums2.size();i++) {
            while(!stack.empty() && nums2[i]> stack.top()) {
                map[stack.top()] = nums2[i];
                stack.pop();
            }
            stack.push(nums2[i]);
        }
        for (int i =0;i<nums1.size();i++) {
            if (map.count(nums1[i])) {
                answer.push_back(map[nums1[i]]);
            } else {
                answer.push_back(-1);
            }
        }
        return answer;
    }
};

int main() {
    auto s = Solution();
    vector<int> nums1 {4,1,2};
    vector<int> nums2 {1,3,4,2};
    // [1, 1, 4, 2, 1, 1, 0, 0]
    auto answer = s.nextGreaterElement(nums1, nums2);
    for (auto &i : answer)
        cout << i << endl;
}
