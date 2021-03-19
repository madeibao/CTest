/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head,ListNode *tail) {  //反转链表模板，建议背住
        auto p1 = head, p2 = head->next;

        while (p2 != tail) {
            auto p3 = p2->next;
            p2->next = p1;
            p1 = p2, p2 = p3;
        }

        return p1;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next) return head;

        auto tail = head;
        for (int i = 0; i < k; i ++ ) {                 //遍历k个节点
            if (!tail) return head;                     //不足k个节点则不反转，直接返回
            tail = tail->next;                          //使尾结点与头结点相距k
        }

        auto newHead = reverse(head, tail);             //反转长度为k的链表
        head->next = reverseKGroup(tail, k);            //递归将下一段反转链表接到当前段的尾部
                                                        //这一段很久都没整明白，稿纸上比划了下才清楚了
        return newHead;
    }
};


