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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* res = head->next, * cur = NULL;
        ListNode* p1 = head, * p2 = p1->next, * newP1 = p2->next;
        res->next = p1;
        cur = p1;
        while(newP1 != NULL && newP1->next != NULL) {
            cur->next = newP1->next;
            ListNode* oldP1 = newP1;
            newP1 = newP1->next->next;
            cur->next->next = oldP1;
            cur = oldP1;
        }
        if(newP1 != NULL) cur->next = newP1;
        else cur->next = NULL;
        return res;
    }
};
