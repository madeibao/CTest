

# 输入的处理
n = int(input())
words = []
for _ in range(n):
    words.append(input())
target = input()


sorted_target = sorted(target)
# 然后在对word排序
ans = []
for word in words:
    sorted_word = sorted(word)
    if sorted_word == sorted_target:
        ans.append(word)
# 看看ans存了啥
if len(ans) > 0:
    ans.sort()
    print(" ".join(ans))
else:
    print("null")