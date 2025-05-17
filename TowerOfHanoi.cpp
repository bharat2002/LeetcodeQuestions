
#include <iostream>
#include <cmath>
using namespace std;

void TowerofHanoi(int n, char source, char destination, char auxiliary)
{
    
    if(n==0)
    {
        return;
    }
    TowerofHanoi(n-1,source,auxiliary,destination);
    printf("Move %d from %c to %c using %c\n", n, source, destination, auxiliary);
    TowerofHanoi(n-1,auxiliary,destination, source);        
     
    

}

int main()
{
    std::cout << "Tower of Hanoi" << std::endl;
    TowerofHanoi(4,'A','C','B');

}