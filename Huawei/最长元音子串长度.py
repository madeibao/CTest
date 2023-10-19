


def max_aeiou(s):
    result = ''
    for i in range(len(s)-1):
        if s[i] not in 'aeiouAEIOU':
            continue
        for j in range(i+1, len(s)):
            if s[j] in 'aeiouAEIOU':
                if len(s[i:j + 1]) > len(result):
                    result = s[i:j+1]
            else:
                break
    return result


print(max_aeiou("asdbuiodevauufgh"))
print("\n")
print(max_aeiou("asdbuiodevauufgh"))



