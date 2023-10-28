

s1 = input()
s2 = input()

def result(s1, s2):
    set1 = set(s1)
    set2 = set(s2)
    set3 = set1.intersection(set2)
    ans = list(set3)
    ans.sort()
    return "".join(ans)
result(s1, s2)