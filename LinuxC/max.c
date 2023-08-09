

#include<stdio.h>

#define max(a,b) ({   \
    int _a = (a);     \
    int _b = (b);     \
    _a > _b ? _a : _b; })


int main() {

    int nums[] = {2,1,2,23,19,20};
    int res = 0;
    int i = 0;
    for(i=0;i<sizeof(nums)/sizeof(nums[0]);i++) {
        res = max(res, nums[i]);
    }

    printf("%d\n",res);
    return 0;
}
