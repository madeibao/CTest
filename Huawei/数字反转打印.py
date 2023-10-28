

# n = int(input())


n = 30
def result():
    printNum = 1 # 每行要打印的数，起始为第一行第一个数1
    for i in range(1, n+1): # 控制行数
        printList = [] # 每行打印的数list
        for j in range(i):
            # 每行多少个数
            printList.append(printNum)
            printNum += 1
        if i%2==0:
            # 如果是偶数行，就要倒序
            printList.reverse() 
        sArr = [] # 处理字符串
        for ele in printList:
            tmp = str(ele)
            # 如果数字不足4位，则后面补足
            while len(tmp)<4:
                tmp += "*" # 事真多
            sArr.append(tmp)
        res = "    ".join(sArr)
        for k in range(n-i):
            # 每行缩进
            res = "    " + res
        print(res)

print(result())

