#include <iostream>
#include <vector>

using namespace std;
int CheckSortedArray(std::vector<int> &nums, int n)
{
    if(n==1)
    {
        return 1;
    }
    return nums[n-1]>=nums[n-2]? CheckSortedArray(nums,n-1):false;
}
int main()
{
    std::vector<int> nums = {1,2,3,5,5};
    std::cout<< CheckSortedArray(nums,nums.size());
}