class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int,int> buf;
        for (int i=0;i<nums.size();i++ ) {
            if (buf.count(nums[i]) != 0) {
                result.push_back(i);
                result.push_back(buf.at(nums[i]));
                break;
            }
            buf[target - nums[i]] = i;
        }
        return result;
    }
};
