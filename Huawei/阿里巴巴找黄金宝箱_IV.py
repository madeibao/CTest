
# 样例
# 输入

# 2,5,2
# 输出

# 5,-1,5
# 说明

# 第一个2的下一个更大的数是5；

# 数字5找不到下一个更大的数；

# 第二个2的下一个最大的数需要循环搜索，结果也是5

# 输入

# 3,4,5,6,3
# 输出

# 4,5,6,-1,4


 
def findNextBig(arr, stack, res):
    for i in range(len(arr)):
        ele = arr[i]
 
        while True:
            if len(stack) == 0:
                stack.append([ele, i])
                break
            else:
                peekEle, peekIdx = stack[-1]
 
                if ele > peekEle:
                    res[peekIdx] = ele
                    stack.pop()
                else:
                    stack.append([ele, i])
                    break
 
 
# 算法入口
def getResult():
    stack = []
    res = [-1] * len(arr)
 
    findNextBig(arr, stack, res)
 
    if len(stack) != 1:
        findNextBig(arr, stack, res)
 
    return ",".join(map(str, res))
 

# 输入获取



arr = list(map(int, input().split(",")))

# 算法调用
print(getResult())