#include <iostream>
#include <vector>
using namespace std;

void printArr(vector<int>& arr)
{
    for(auto i:arr)
    {
        std::cout<<i<<" ";
    }
    std::cout<<endl;
}
void generateAllSubstring(int n,std::vector<int>& arr)
{
    if(n<1)
    {
        printArr(arr);
    }
    else
    {
        arr[n-1] = 0;
        generateAllSubstring(n-1, arr);
        arr[n-1] = 1;
        generateAllSubstring(n-1, arr);
    }

}

int main()
{
    std::vector<int> arr = {1,1,1};
    generateAllSubstring(3, arr);
}