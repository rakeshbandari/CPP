#include <iostream>
#include <stdio.h>
using namespace std;
 
int max(int x, int y) {
    return (x > y) ? x : y;
}
 
int trap(int heights[], int n)
{
    int left = 0, right = n - 1, water = 0;
 
    int maxLeft = heights[left];
    int maxRight = heights[right];
 
	while(left <= right)
	{
        maxLeft  = max(maxLeft, heights[left]);
        maxRight = max(maxRight, heights[right]);

        if(maxLeft < maxRight){
            water += maxLeft - heights[left++];
        }
        else {
            water += maxRight - heights[right--];
        }
    }
 
    return water;
}
 
int main(void)
{

    int heights[] = { 0,1,0,2,1,0,1,3,2,1,2,1 };
    int n = sizeof(heights) / sizeof(heights[0]);
 
    printf("The maximum amount of water that can be trapped is %d",
            trap(heights, n));
 
    return 0;
}
