

n = int(input())
arr = [list(map(int, input().split(","))) for i in range(n)]
print(n)
print(arr)


def result(rans , n):
    rans.sort(key=lambda x:x[0])
    stack=[rans[0]]
    # 已经把第一个加进去了，所以
    for i in range(1, n):
        ran = rans[i]
        while True:
            if len(stack)==0:
                stack.append(ran)
                break
            s0, e0 = stack[-1]
            s1, e1 = ran
            # 因为按照start升序排列，s1一定是大于s0的啊
            if s1<=s0:
                if e1<=s0:
                    break
                elif e1<e0:
                    break
                else:
                    stack.pop()
            elif s1<e0:
                if e1<=e0:
                    break
                else:
                    stack.append(([e0, e1]))
                    break
            else:
                stack.append(ran)
                break
    return len(stack)
print(result(arr, n))


# 3
# 1,4 
# 2,5
# 3,6
# 3
# [[1, 4], [2, 5], [3, 6]]
# 2