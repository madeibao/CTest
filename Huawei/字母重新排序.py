



stra = input()
strb = input()

def result():
    seta = set(stra)
    setb = set(strb)

    set3 = seta.intersection(setb)

    ans = list(set3)
    ans.sort()
    return "".join(ans)

print(result())


bach
bbaaccedfg