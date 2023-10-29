

n = int(input())
# 4
# a 1 3
# a 2 2
# a 3 2
# p
seq = [list(input().split()) for i in range(n)]
# print(n)
# print(seq)


import heapq as hq
def result():
    ans = []
    hq.heapify(ans)
    for i in range(n):
        if seq[i][0] == "a":
            # a, id, priority
            hq.heappush(ans, [int(seq[i][2]), int(seq[i][1])])
        elif seq[i][0] == "p":
            if hq:
                print(ans[0][1])
            else:
                print("")

print(result())

