



arr = list(input().split())

def result(arr):
    arr.sort(key=lambda x:x.lower()) # 先使用小写字母拍一遍序。
    stack = [arr[0]]                 # 添加到stack里。
    for i in range(1, len(arr)-1):   # 因为这里只会加元素，要么就不让进，所以就不会stack非空判断。
        top = stack[-1].lower()
        s = arr[i]                   # 注意后面添加到stack的时候是添加arr[i] 而不是arr[i].lower()
        now = arr[i].lower()
        if top == now:
            continue
        stack.append(s)
    return " ".join(stack)


print(result(arr))

