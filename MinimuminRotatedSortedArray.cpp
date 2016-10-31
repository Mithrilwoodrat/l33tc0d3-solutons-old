#include <iostream>
#include <vector>

void findMin(std::vector<int>& nums)
{
    int last = nums[0];
    if (nums.size() == 1)
        return last;
    for (auto & i : nums)
    {
        std::cout<< i << std::endl;
        if (last > i)
        {
            std::cout << i << "is the minimum" << std::endl;
            break;
        }
        last = i;
    }    
    return nums[0];
}


int main(void)
{
    std::vector<int> nums {4,5,6,7,0,1,2};
    findMin(nums);
    return 0;
}

