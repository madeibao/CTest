


def main():
    s, t, a, b = map(int, input().split())
    res = solve_method(s, t, a, b)
    print(res)


def solve_method(s, t, a, b):
    diff = abs(s - t)
    min1 = 0
    tmp = diff
    while tmp % b != 0:
        tmp -= a
        min1 += 1

    tmp = diff
    min2 = 0
    while tmp % b != 0:
        tmp += a
        min2 += 1

    return min(min1, min2)


if __name__ == "__main__":
    main()