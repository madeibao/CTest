

from typing import List


class Solution:
    def smallestStringWithSwaps(self, s: str, pairs: List[List[int]]) -> str:


    	list2 = list(s)
    	for i in pairs:
    		list2[i[0]],list2[i[1]] = list2[i[1]],list2[i[0]]

    	return "".join(list2)
    	

if __name__ == "__main__":
	s = Solution()
	s2 = "dcab"
	pairs = [[0,3],[1,2]]
	print(s.smallestStringWithSwaps(s2,pairs))


