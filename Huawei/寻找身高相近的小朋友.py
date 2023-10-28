


h, n = map(int, input().split())
heights = list(map(int, input().split()))
print(h, n)
print(heights)


def result():
    heights.sort(key= lambda x: (abs(x-h), x))
    return " ".join(map(str, heights))
print(result())