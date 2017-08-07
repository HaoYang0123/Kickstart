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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || head == NULL) return head;
        ListNode *p1 = head, *p2 = head;
        int n = 0;
        while(p2 != NULL && k--) {
            p2 = p2->next;
            ++n;
        }
        if(p2 == NULL) { //证明k比链表长度大，则需要使用k%n赋值给k
            k = k % n;
            p2 = head;
            while(k--) {
                p2 = p2->next;
            }
        }
        ListNode *preP1 = p1, *preP2 = p2;
        while(p2 != NULL) {
            preP1 = p1;
            p1 = p1->next;
            preP2 = p2;
            p2 = p2->next;
        }
        if(preP1 == p1 || p1 == NULL) return head;
        preP2->next = head;
        preP1->next = NULL;
        return p1;
    }
};
