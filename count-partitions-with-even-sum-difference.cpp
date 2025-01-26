#include <iostream>
#include <vector>
using namespace std;

class Solutuon {
public:
    int countPartitions(vector<int>& nums) 
    {
        int n = nums.size();
        int sum = 0;
        int ans = 0;
        int leftsum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
        }   
        for(int i = 0; i < n-1; i++)
        {
            leftsum += nums[i];
            int rightsum = sum - leftsum;
            if((leftsum - rightsum) % 2 == 0)
                ans++;
            
        }
        return ans;
    }
};

int main() 
{
    Solutuon s;
    vector<int> arr = {1,2,2};
    cout << s.countPartitions(arr);
    return 0;
}