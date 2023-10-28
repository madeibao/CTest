# 输入
newspaper = input().split(" ")
anonymousLetter = input().split(" ")
print(newspaper)
print(anonymousLetter)



def result(newspaper, anonymousLetter):
    count = {}
    for s in newspaper:
        s = "".join(sorted(s))
        if count.get(s) is None:
            count[s] = 1
        else:
            count[s] += 1
    flag = True
    for s in anonymousLetter:
        s = "".join(sorted(s))
        if count.get(s) is None and count[s] > 0:
            count[s] -= 1
        else:
            flag = False
            break
    return str(flag).lower()

print(result(newspaper, anonymousLetter))