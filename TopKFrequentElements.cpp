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
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;
        vector<pair<int,int> > top(k);
        vector<int> ans;
        int i,j;
        //cout << nums.size() << k << endl;
        if (nums.size() == 0){
            return ans;
        }
        // for(i=0;i<k;i++) {
        //     cout << top[i].first << "," << top[i].second << endl;
        // }
        for(i=0;i<nums.size();i++) {
            if(freq.count(nums[i]))
                freq[nums[i]]++;
            else
                freq[nums[i]] = 1;
        }
        std::copy(freq.begin(), freq.end(),
              std::back_inserter(top));
        auto cmp = [](std::pair<int, int> const & a,std::pair<int, int> const & b)
        {
            return a.second != b.second ? a.second > b.second : a.first < b.first;
        };
        std::sort(top.begin(),top.end(), cmp);
        for(i=0;i<k;i++) {
            ans.push_back(top[i].first);
        }
        return ans;
    }
};


int main() {
    auto s = Solution();
    // vector<int> nums {1,1,1};
    // auto answer = s.subarraySum(nums, 2);
    // cout << answer << endl;

    //vector<int> nums {1,1,1,2,2,3};
    vector<int> nums {3,2,3,1,2,4,5,5,6,7,7,8,2,3,1,1,1,10,11,5,6,2,4,7,8,5,6};

    cout << "nums: ";
    for(int j=0;j<nums.size();j++) {
            cout << nums[j] << " ";
    }
    cout <<endl;
    

    //auto ans = s.topKFrequent(nums, 2);
    auto ans = s.topKFrequent(nums, 10);
    for(auto & i: ans){
        cout << i << " ";
    }
    cout << endl;
}