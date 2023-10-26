


def dfs(case, used, index):
    ans = 0
    for i in range(index, len(case)-2):
        # 如果标记为使用过了，就跳过
        if used[i]:
            continue
        for j in range(i+1, len(case)-1):
            if used[j]:
                continue
            for k in range(j+1, len(case)):
                if used[k]:continue
                # case排好序的。
                if case[i]**2 + case[j]**2  ==case[k]**2:
                    # 三个数都标记为使用过了。
                    used[i]=True
                    used[j]=True
                    used[k]=True
                    # 递归，这里统计的是个数，所以要加上现在的呀。
                    ans = max(ans, dfs(case, used, i+1) + 1)
                    # 回溯一波
                    used[i]=False
                    used[j]=False
                    used[k]=False
    return ans

def result(cases):
    # 有多个cases测试数据，所以
    for case in cases:
        case.sort()
        return dfs(case, [False]*len(case), 0)


if __name__=="__main__":
    # 数据获取
    n = int(input())
    # 1
    # 7 3 4 5 6 5 12 13
    cases = [list(map(int, input().split()))[1:] for _ in range(n)]
    res = result(cases)
    print(res)





# 1
# 7 3 4 5 6 5 12 13