

n = int(input())
arr = list(map(int, input().split()))
# 123 124 125 121 119 122 126 123
print(n)
print(arr)


def result():
    # 当前值跟栈顶比较，只要栈顶元素比他小，就弹出来。并且弹出来的这个id，对应第一个比他大的数就是当前值的id
    # 当前值<=栈顶，就把[元素值，id]加入栈中。其实就是单调栈的应用。
    stack = []
    res = [0] * len(arr)
    for i in range(len(arr)):
        ele = arr[i]
        while True:
            # 栈为空
            if len(stack) == 0:
                stack.append([ele, i])
                break
            # 栈不为空,就要跟现在的比较。
            peekEle, peekIdx = stack[-1]
            if ele > peekEle: # 当前元素的值大于peekEle，那不相当于peekEle第一个比他大的数要更新为i
                res[peekIdx] = i
                stack.pop()#把前面的数据弹出来。
            else:
                # ele <= peekEle
                stack.append([ele, i])
                break
    return " ".join(map(str, res))
print(result())