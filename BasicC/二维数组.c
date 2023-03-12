




#include<stdio.h>
#include<string.h>

int main() {

    //定义一个二维数组
    int nums[2][2] = {
        {100, 2},
        {202, 300}
    };

    //此时 nums[0]、和 nums[1]各为一个数组
    int *p[2] = {nums[0], nums[1]};

    //我们可以用指针数组 p 操作一个二维数组

    //p 为数组 p 的首地址，p[0] = nums[0] = *p，**p = nums[0][0]
    printf("nums[0][0] = %d\n", **p);

    //指针 + 整数形式，p+1 移动到 nums 的地址，*(p +1) = nums[1]，则**(p + 1) = nums[1][0]
    printf("nums[1][0] = %d\n", **(p + 1));

    //先*p = nums[0]，再*p + 1 = &nums[0][1]，最后获取内容*(*p + 1)即为 nums[0][1]
    printf("nums[0][1] = %d\n", *(*p + 1));

    return 0;
}
