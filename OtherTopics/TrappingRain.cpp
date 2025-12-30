#include <iostream>
#include <climits>
using namespace std;

void trappedWater(int *heights, int n)
{
    int leftMax[1000], rightMax[1000];

    leftMax[0] = heights[0];
    rightMax[0] = heights[0];

    for (int i = 1; i < n; i++)
    {
        leftMax[i] = max(leftMax[i - 1], heights[i - 1]);
    }

    for (int i = n - 2; i >= 0; i--)
    {
        rightMax[i] = max(rightMax[i + 1], heights[i + 1]);
    }
    int trappedWater = 0;
    for (int i = 0; i < n; i++)
    {
        int currentTrapped = min(leftMax[i], rightMax[i]) - heights[i];
        if (currentTrapped > 0)
        {
            trappedWater += currentTrapped;
        }
    }

    cout << "Total trapped Water is :" << trappedWater << endl;
}

int main()
{
    int heights[] = {4,3,2,1,0};
    int n = sizeof(heights) / sizeof(int);
    trappedWater(heights,n);
    return 0;
}