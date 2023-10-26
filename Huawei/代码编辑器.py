


def result():
    str2 = list(str1)
    index = 0
    for op, val in operations:
        if op == "FORWARD":
            index = min(index+int(val), len(str2))
        elif op == "BACKWARD":
            index = max(index - int(val), 0)
        elif op == "SEARCH-FORWARD":
            i = str1.find(value, index) #
            if i != -1: # 如果没有找到，index不变。
                index = i # SEARCH-FORWARD word从指针当前位置向前查找word并将指针移动到word的起始位置，如果未找到则保持不变
        # SEARCH-BACKWARD word在文本中向后查找word并将指针移动到word的起始位置，如果未找到则保持不变
        elif op == "SEARCH-FORWARD":
            j = str1.rfind(value, 0, index)
            if j != -1: # 找到了才变
                index = j
        elif op == "INSERT":
            str2.insert(index, val)
            index += len(val)
        elif op == "REPLACE":
            str2[index:index+len(val)] = val # 优秀啊，直接换 # 注意区间，左闭右开。index+len(val)-1 + 1
        elif op == "DELETE":
            del str2[index:index+int(val)] # 注意这里是左闭右开区间哈。
    print("".join(str2))


if __name__=="__main__":

    k = int(input())
    str1 = input() # 原始文本
    operations = []
    for i in range(k):
        op, value = input().split()
        operations.append((op,value))
    # print(k)
    # print(str1)
    # print(operations)

    result()

