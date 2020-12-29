while True:
    try:
        n = int(input())
        f = [0,1]
        while f[1] < n:
            t = f[1]
            f[1] = f[0] + f[1]
            f[0] = t

        ans = min(n - f[0], f[1] - n)
        print(ans)
    except:
        break




while True:
    try:
        n = int(input())
        f = [0,1]
        while f[1] < n:
            t = f[0] +f[1]
            f[0] = f[1]
            f[1] = t

        ans = min(n - f[0], f[1] - n)
        print(ans)
    except:
        break

