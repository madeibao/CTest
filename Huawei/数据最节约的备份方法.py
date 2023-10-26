nums = list(map(int, input().split(",")))
# 100,500,300,200,400
print(nums)



def partition(buckets, nums, index):
    # 注意这个index是nums的index
    # 先干了边界条件。
    if index == len(nums):
        # 证明分完了，返回True
        return True
    # 选求
    select = nums[index]
    # 然后遍历桶
    for i in range(len(buckets)):
        # 如果两个桶现有装的一样多，直接剪枝
        if i>0 and buckets[i] == buckets[i-1]:
            continue
        # 如果选的数与当前的桶装的东西求和小于500，那就放
        if buckets[i] + select <= 500:
            buckets[i]+=select
            # 放好了这个球，接着放下一个球，递归下去，
            # 这里更新的是index变成index+1
            if partition(buckets, nums, index+1):
                # 递归下一步得到的结果是True，那我返回给上一层也是True
                return True
    # 桶放完了还没满足要求
    return False

def check(cnt, nums):
    # nums数组中的数是否可以分成cnt组，每组之和<=500
    # 使用回溯算法，cnt个桶来装，每个容量是500，nums的文件是小球，小球放到桶里
    buckets = [0]*cnt
    return partition(buckets, nums, 0)


def result():
    # 文件降序排列。
    nums.sort(reverse=True)
    # 至少分1组，最多分len(nums)组
    l , r= 1, len(nums)
    ans = r
    # 二分开始
    while l <= r:
        m = (l+r)//2
        if check(m, nums):
            ans = m
            # 继续尝试更小解
            r = m - 1
        else:
            l = m + 1
    return ans

print(result())