


numa = list(map(int,input().split()))[1:]
numb = list(map(int,input().split()))[1:]

k = int(input())


def getResult():
    pairs= []

    for a in numa:
        for b in numb:
            pairs.append(a+b)

    pairs.sort()

    sumS = 0
    for i in range(k):
        sumS+=pairs[i]
    
    return sumS

print(getResult())


# 3 1 1 2
# 3 1 2 3
# 2
