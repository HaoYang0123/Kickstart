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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        int jw = 0, bit = l1->val + l2->val;
        if(bit >= 10) { 
            bit %= 10;
            jw = 1;
        }
        ListNode* res = new ListNode(bit), *cur = res;
        l1 = l1->next;
        l2 = l2->next;
        while(l1 != NULL && l2 != NULL) {
            bit = l1->val + l2->val + jw;
            if(bit >= 10) {
                bit %= 10;
                jw = 1;
            }
            else jw = 0;
            cur->next = new ListNode(bit);
            cur = cur->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL) {
            bit = l1->val + jw;
            if(bit >= 10) {
                bit %= 10;
                jw = 1;
            }
            else jw = 0;
            cur->next = new ListNode(bit);
            cur = cur->next;
            l1 = l1->next;
        }
        while(l2 != NULL) {
            bit = l2->val + jw;
            if(bit >= 10) {
                bit %= 10;
                jw = 1;
            }
            else jw = 0;
            cur->next = new ListNode(bit);
            cur = cur->next;
            l2 = l2->next;
        }
        if(jw == 1) cur->next = new ListNode(1);
        return res;
    }
};
