
# 3 3
# 2 3 5
# 3 4 7
# 3 5 8
# 4



import sys
lines = sys.stdin.readlines()
matrix = lines[1:-1]
x = lines[-1].strip()
flag = False
for m_ in matrix:
    if x in m_:
        flag = True
        break
if flag:
    print('true')
else:
    print('false')

    