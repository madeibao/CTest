


import copy
def canMerge(m, n):
    # 从用例 1 输出的 2,3,2 来看，未合并的端口组是不能去重和排序的，因此这里需要浅克隆下，避免改变原数组顺序
    # 或者在这里加边界条件
    if m is None or n is None or len(m)<2 or len(n)<2:return False
    m = copy.copy(m)
    n = copy.copy(n)
    m.sort() # 排序下，很容易想到的
    n.sort()
    i= 0
    j = 0
    count = 0 # 初始化
    # 考虑边界条件。
    while i<len(m) and j <len(n) and count < 2:
        # 三种情况，逐一分析。
        if m[i] == n[j]:
            i+=1
            j+=1
            count+=1
        elif m[i]>n[j]:
            j+=1
        else:
            i+=1
    return count>=2 # 判断是否大于2

def result(matrix):
    flag = True
    while flag:
        flag = False # 进来先给他置为false
        # 一个个来
        for i in range(len(matrix)-1, 0 ,-1):
            for j in range(i-1,-1,-1):
                if canMerge(matrix[i], matrix[j]):
                    tmp = []
                    # 先把matrix[i]搞进来，而不是append，这里要注意下。
                    tmp.extend(matrix[i])
                    tmp.extend(matrix[j])
                    matrix[j] = list(sorted(set(tmp))) # 这一步厉害啊，先用set进行去重，然后进行排序。优秀。
                    matrix[i] = None # 把matrix[i]置空。i比j小，所以下一次循环的时候还是能把j跟大伙比一遍
                    flag = True # 这里要给他搞成true，就是让他再进行比较一遍。
                    break # 这里就是要实现，合并之后，还能把所有的比一遍。
    return list(filter(lambda x:x is not None, matrix))


m = int(input())
arr = [list(map(int, input().split(","))) for i in range(m)]
print(m)
print(arr)


# m = 6
# arr = [[10], [4, 2, 1], [9], [3, 6, 9, 2], [6, 3, 4], [8]]
if m>10 or m<1:
    print("[[]]")
else:
    print(result(arr))


# 3
# 2,3,1
# 4,3,2
# 5
# 3
# [[2, 3, 1], [4, 3, 2], [5]]
# [[1, 2, 3, 4], [5]]