
v1 = input()
v2 = input()
print(v1)
print(v2)


def rmLeadZero(x):
    tmp = x.lstrip('0')
    return "0" if tmp == "" else tmp

# 将大版本按"."切割为子版本列表
def convert(version):
    return list(map(rmLeadZero, version.split(".")))
def result():
    arr1 = convert(v1)
    arr2 = convert(v2)
    n = max(len(arr1), len(arr2))
    for i in range(n):
        # 空字符和 0 相等，比如 1 和 1.0 相等 把他补0
        tmp1 = arr1[i] if len(arr1)-1>=i else "0"
        tmp2 = arr2[i] if len(arr2)-1>=i else "0"
        if tmp1 > tmp2:
            return 1
        elif tmp1<tmp2:
            return -1
    # 比完了，还没得到结果。就只能返回0
    return 0
print(result())


# 5.6.8.a
# 5.6.8.0a