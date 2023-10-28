
issues = input().split(",")
answers = input().split(",")
# bdni,wooood
# bind,wrong,wood
print(issues)
print(answers)


# 这里展示任选一个满足就行。
def result():
    ans = []
    for issue in issues:
        # 去重然后排序。
        sortedIssue = "".join(sorted(issue))
        distinctIssue = "".join(set(issue))
        for answer in answers:
            sortedAnswer = "".join(sorted(answer))
            distinctAnswer = "".join(set(answer))
            if sortedIssue == sortedAnswer or distinctIssue==distinctAnswer:
                ans.append(answer)
                find= True
                # break
                # 如果一个谜面对应多个谜底，这里就不能break，如果一个谜面只对应一个谜底，那这里就要break，考试的时候都试下
        if not find:
            ans.append("not found")
    return ",".join(ans)


print(result())
