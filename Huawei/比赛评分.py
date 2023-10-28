

import functools
'''
4,5
10,6,9,7,6
9,10,6,7,5
8,10,6,5,10
9,10,8,4,9
'''
m, n = map(int, input().split(","))
scores = [list(map(int, input().split(","))) for _ in range(m)] # m个评委，n个选手。
print(m, n)
print(scores)


def cmp(a, b):
    if a["sum"] != b["sum"]:
        return b["sum"]-a["sum"]
    # 相等了
    for i in range(m):
        if a["score"][i] == b["score"][i]:
            continue
        return b["score"][i] - a["score"][i]
    return 0 # 啥比不出来了。
def result():
    if m<3 or m>10 or n<3 or n>100: # 题目给的边界条件啊。
        return "-1"
    players = []
    for j in range(n): # 先遍历选手
        player = []
        for i in range(m): # 某个选手的分。
            # 先进行判断。
            if scores[i][j] >10 or scores[i][j]<1:
                return "-1"
            # 如果没有return
            player.append(scores[i][j])
        player.sort(reverse=True) # 对某个选手的分数进行降序排列
        # 排完之后加入到players里
        players.append({"id":j, "sum":sum(player), "score":player}) # 这个厉害啊。
    players.sort(key=functools.cmp_to_key(cmp))

    # python3 取消了cmp 参数，可以用functools.cmp_to_key 代替

    # 0号下标数字表示1号选手分数，1号下标数字表示2号选手分数，依次类推
    return ",".join(list(map(lambda x:str(x["id"]+1), players[:3])))


print(result())

