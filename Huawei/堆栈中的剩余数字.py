

def push(num, stack):
    total = num
    for i in range(len(stack)-1, -1, -1):
        total-=stack[i]
        if total == 0:
            del stack[i:]
            push(num * 2, stack)
            return
        elif total<0:
            break # 这里不是continue因为小于0了。补不上了。所以结束循环。
    # 最后别忘记了把num入栈
    stack.append(num) # 注意这里在循环外面。
def result(nums):
    stack = [nums[0]]
    for i in range(1, len(nums)):
        push(nums[i], stack)
    stack.reverse()
    return " ".join(map(str, stack))

nums = list(map(int, input().split(",")))
print(nums) # [5, 10, 20, 50, 85, 1]

print(result(nums))