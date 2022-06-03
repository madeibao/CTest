

from typing import List

class ListNode(object):
	def __init__(self,x):
		self.val = x
		self.next = None



class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        if not head or not head.next:return True
        stack = []
        while head:
            stack.append(head.val)
            head = head.next
        return stack==stack[::-1]



if __name__ == '__main__':

	head= ListNode(1)
	h2 = ListNode(2)
	h3 = ListNode(1)

	head.next = h2
	h2.next = h3
	h3.next = None

	s = Solution()
	print(s.isPalindrome(head))

