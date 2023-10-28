

prefix, suffix = input().split(",")
print(prefix, suffix)


def result():
    global prefix # 声明前缀
    global suffix # 声明后缀
    if len(prefix) == 0: # 前缀没有
        prefix = "/"
    if len(suffix) == 0: # 后缀没有
        suffix = "/"
    if prefix[-1] == "/" and suffix[0] == "/": # 如果前缀结尾和后缀开头都为/，需要自动去重
        return prefix + suffix[1:]
    if prefix[-1] != "/" and suffix[0] != "/": # 如果前缀结尾和后缀开头都没有/，需要自动补上/连接符
        return prefix + "/" + suffix
    # 前缀末尾有"/",后缀开头无"/"
    # 前缀末尾无"/",后缀开头有"/"
    return prefix+suffix
print(result())