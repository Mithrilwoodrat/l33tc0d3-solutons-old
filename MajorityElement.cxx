// Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

// You may assume that the array is non-empty and the majority element always exist in the array.

#include<algorithm>
class Solution {
public:
    int majorityElement(vector<int> &num) {
        vector <int>::iterator Iter; 
        int cur_num = 0;
        int count = 0;
        int limit = num.size()/2;
        
        for (int i=0;i<num.size();i++)
        {
            if(count == 0)
            {
                cur_num = num[i];
                count = 1;
            }
            else
            {
                if(num[i] == cur_num)
                    count++;
                else
                    count--;
            }
        }
        return cur_num;
    }
};
