

def result2(input_arr,n,m):
    output_arr = [] # 用来接收出列的数据。
    num = 0 # 开始计数。
    while len(input_arr)>0: # 题目说的直到数列所有数值出列为止
        num+=1 # 循环就要加一
        count = input_arr.pop(0)
        if num == m:
            output_arr.append(count)
            m = count # 题目说的，更新m的值。
            num = 0 # 更新到初始状态，因为进入下一个循环他要自己加1的。
        else:
            input_arr.append(count) # 小朋友站到最后面。
    return ",".join(map(str, output_arr))


# input_arr = [3, 1, 2, 4]
# n, m = 4, 7
# result2(input_arr,n,m)

input_arr = list(map(int, input().split(",")))
n = int(input())
m = int(input())

print(result2(input_arr,n,m))