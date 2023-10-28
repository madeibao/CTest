
n = int(input())
ids = list(map(int,input().split(",")))
# 13
# 3,3,7,4,4,4,4,7,7,3,5,5,5
# 53,80,68,24,39,76,66,16,100,55,53,80,55
scores = list(map(int,input().split(",")))
print(ids)
print(scores)


def result():
    players = {}
    for i in range(n):
        players.setdefault(ids[i], []) # 初始化，key = ids[i] value = []
        players.get(ids[i]).append(scores[i])
    ans = []
    for pid in players:
        if len(players[pid]) >= 3:
            players[pid].sort(reverse = True) # 倒序排列。然后取前三的和嘛。
            ans.append((pid, sum(players[pid][:3])))
    ans.sort(key= lambda x:(-x[1], -x[0]))
    return ",".join(map(lambda x: str(x[0]), ans))
print(result())