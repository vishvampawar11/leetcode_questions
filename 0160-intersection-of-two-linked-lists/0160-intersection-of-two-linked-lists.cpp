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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p = headA, *q = headB, *ans = NULL;
        while(p) {
            p->val-=1e6;
            p=p->next;
        }
        while(q) {
            if(q->val<0) {
                ans = q;
                break;
            }
            q=q->next;
        }
        p = headA;
        while(p) {
            p->val+=1e6;
            p=p->next;
        }
        return ans;
    }
};