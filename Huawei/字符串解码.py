



# @Time   :2019/01/31
# @Author :LiuYinxing
# 栈操作

class Solution:
    def decodeString(self, s: str) -> str:
        res, stack, tmp_cnt = '', [], 0

        for c in s:
            if c == '[':  # 遇到 [ 进栈
                stack.append((tmp_cnt, res))
                tmp_cnt, res = 0, ''   # 重置为0和空，重新开始进入下一个 []
            elif c == ']':  # 出栈的情况
                cnt, last_res = stack.pop()
                res = last_res + cnt * res
            elif '0' <= c <= '9':  # 处理数字部分
                tmp_cnt = tmp_cnt * 10 + int(c)
            else:
                res += c
        return res


if __name__ == '__main__':
    solu = Solution()
    # // S = 'ef3[a]2[bc]gh'
    S = '3[a2[c]]'
    print(solu.decodeString(S))
