'''

4
6
word
dd
da
dc
dword
d

'''




k = int(input())
n = int(input())
words = [input() for i in range(n)]
print(k, n)
print(words)


def result(k, n, words):
    chain = [words.pop(k)]
    # 统计前缀。
    prefix = {}
    # 单词的第一个字母为key，然后加入列表中。
    for word in words:
        w = word[0]
        if prefix.get(w) is None:
            prefix[w] = []
        prefix[w].append(word)
    # 开始对表进行排序。存在多个首字母相同的单词时，取长度最长的单词，如果长度也相等，则取字典序最小的单词
    for w in prefix.keys():
        prefix[w].sort(key= lambda x: (-len(x), [ord(i) for i in x]))
    # 开始循环。
    while True:
        # 拿到chain的倒数第一个单词的最后一个字母。
        tail = chain[-1][-1]
        if prefix.get(tail):
            # 存在，就要把prefix[tail]弹出第一个。因为题目说了单词不能重复使用。
            chain.append(prefix[tail].pop(0))
        else:
            break
    return "".join(chain)
print(result(k, n, words))