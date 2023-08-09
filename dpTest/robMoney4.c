
#include<stdio.h>
#include<stdlib.h>

#define MAX(x,y) (x)>(y)?(x):(y)
int rob(int* nums, int numsSize)
{
    if(numsSize == 0)   return 0;
    if(numsSize == 1)   return nums[0];
    if(numsSize == 2)   return MAX(nums[0],nums[1]);
    int *dp = (int *)malloc(sizeof(int)*numsSize);
    memset(dp,0,numsSize);

    int i = 0;
    int res = 0;
    for(i=0; i<numsSize; i++)
    {
        if(i == 0)
        {
            dp[i] = nums[0];
            continue;
        }
        if(i == 1)
        {
            dp[i] = MAX(nums[0],nums[1]);
            continue;
        }
        dp[i] = MAX(dp[i-1],dp[i-2]+nums[i]);
        res = MAX(res,dp[i]);
    }
    return res;
}

int main() {

    int nums[] = {1,2,3,1};
    int res = 0;
    res = rob(nums,sizeof(nums)/sizeof(nums[0]));
    printf("%d\n",res);

    return 0;
}
