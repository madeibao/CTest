

import re
s = input()
# s="I am an 20-years out---standing @*-stu-dent"
def result():
    # 正则表达式，^ 表示匹配字符串的开始位置 (例外 用在中括号中[ ] 时,可以理解为取反,表示不匹配括号中字符串)
    # $ 表示匹配字符串的结束位置
    # 非字母、数字、-的字符都当成单词之间的分隔符
    words = re.split(r"[^0-9a-zA-Z\-]", s)

    print(words)
    ans = []
    for i in range(len(words)-1, -1, -1):
        word = words[i]
        if word == "":
            continue
        word = word.strip("-") # 去除-单词左右边不能是 "-"
        # { } 大括号用于限定匹配次数 如 {n}表示匹配n个字符 {n,}表示至少匹配n个字符 {n,m}表示至少n,最多m
        subword = re.split(r"-{2,}", word) # "--"为分割符
        for j in range(len(subword)-1, -1, -1):
            if subword[j] != "":
                ans.append(subword[j])
    return " ".join(ans)
print(result())