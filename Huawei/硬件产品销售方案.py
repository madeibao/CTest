
# amount = int(input())
# prices = eval(input())
# print(amount, prices)


def dfs(total, arr, index, sum ,path,res):
    if sum >= total:# 这个是需要的。万一sum>total没有return掉就死循环了
        if sum == total:
            res.append(path[:])
        return
    for i in range(index, len(arr)):
        path.append(arr[i])
        dfs(total, arr, i, sum+arr[i], path, res)
        path.pop()

res = []
amount =500
prices = [100, 200, 300, 500]
dfs(amount, prices, 0, 0, [], res)
print(res)