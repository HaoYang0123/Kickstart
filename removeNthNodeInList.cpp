/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* t1 = head, * t2 = head, * prevT1 = head;
        while(n--) {
            t2 = t2->next;
        }
        while(t2 != NULL) {
            prevT1 = t1;
            t1 = t1->next;
            t2 = t2->next;
        }
        if(t1 == head) //删除表头
            return head->next;
        prevT1->next = t1->next;
        return head;
    }
};
