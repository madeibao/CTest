


from typing import List

class Solution:
    def mostWordsFound(self, sentences: List[str]) -> int:
        return max([len(x.split()) for x in sentences])

if __name__ == '__main__':
	list2 = ["alice and bob love leetcode", 
	"i think so too", "this is great thanks very much"]
	s = Solution()
	print(s.mostWordsFound(list2))