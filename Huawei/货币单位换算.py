

n = int(input())
arr = [input() for i in range(n)]
print(n, arr)


import re
import math
def result(n, arr):
    # \d+ 匹配一个或者多个数字。
    pattern = r"(\d+)((CNY)|(JPY)|(HKD)|(EUR)|(GBP)|(fen)|(cents)|(sen)|(eurocents)|(pence))"
    dic = {
        "CNY":100,
        "JPY": 100 / 1825 * 100,
        "HKD": 100 / 123 * 100,
        "EUR": 100 / 14 * 100,
        "GBP": 100 / 12 * 100,
        "fen": 1,
        "cents": 100 / 123,
        "sen": 100 / 1825,
        "eurocents": 100 / 14,
        "pence": 100 / 12
    }
    ans = 0
    for s in arr:
        result = re.findall(pattern, s)
        print(result)
        for item in result:
            amount = item[0]
            unit = item[1]
            ans += int(amount) * dic[unit]
    return math.floor(ans)
print(result(n, arr))