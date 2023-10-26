
2
1 2
2 1




n = int(input()) # n --- 砝码的种数
m = list(map(int, input().split()))  # 每种砝码的重量
x = list(map(int, input().split()))  # 每种砝码对应的数量
amount = []
weights = {0,}
for i in range(n):
    for j in range(x[i]):
        amount.append(m[i])

for i in amount:
    for j in list(weights):
        weights.add(i+j)
print(len(weights))
