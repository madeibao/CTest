

arr = list(map(int, input().split()))
print(arr)


def check(arr):
    # 先把对角线的算出来。
    a = arr[0][0]*arr[1][1]*arr[2][2]
    b = arr[0][2]*arr[1][1]*arr[2][0]
    # 算每行
    if a !=b:return False
    for i in range(3):
        tmp = 1
        for j in range(3):
            tmp *= arr[i][j]
        if tmp != a: return False
    i, j =0, 0 # 算每列
    for j in range(3):
        tmp = 1
        for i in range(3):
            tmp *= arr[i][j]
        if tmp != a: return False
    return True


    
def result(arr):
    path = []
    ans = []
    used = [0]*len(arr)
    def backtracking(arr, used):
        if len(path) == len(arr):
            tmp = path[:]
            if check([tmp[i*3: i*3+3]for i in range(3)]):
                # print(" ".join(map(str, tmp)))
                ans.append(tmp)
            return 
        for i in range(0, len(arr)):
            if used[i] == 1: continue # 用过的就跳过，不再使用。
            used[i] = 1 # 先把他处理成用过的
            path.append(arr[i]) # 加入path中。
            backtracking(arr, used) #递归一次。
            used[i] = 0 # 恢复成没用过。
            path.pop() # 从path里恢复成没用过

    backtracking(arr, used) # 调用回溯算法，得到满足条件的列表。剩余的就是排序了。
    ans.sort(key=lambda x:(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8])) # 着排列也是绝了。
    for i in ans:
        print(" ".join(map(str, i)))


result(arr)


# 75 36 10 4 30 225 90 25 12