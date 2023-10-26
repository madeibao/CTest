

m, n = map(int, input().split())
'''
3 1
3 15 ()
1 20 (2)
2 10 (3)
'''
children = {}
cap = {}
for _ in range(m):
    fa_id, fa_cap, ch_str = input().split()
    children[fa_id] = []
    cap[fa_id] = int(fa_cap)
    if len(ch_str) > 2:
        children[fa_id].extend(ch_str[1:-1].split(","))
def result(target):
    ans = 0
    stack = [target] # 初始化，先把目标加进来先把他加进来，
    while len(stack)>0:
        id = stack.pop()
        if cap.get(id) is None:
            # 没有id，
            continue
        ans += cap[id] # 把当前的装的值加进来。
        stack.extend(children[id]) # 把children的id加进来。这里是extend
    return ans
print(result(str(n)))


'''
3 1
3 15 ()
1 20 (2)
2 10 (3)



'''