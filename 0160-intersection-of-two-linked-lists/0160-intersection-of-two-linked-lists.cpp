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
        int l1=0, l2=0;
        ListNode *p = headA, *q = headB;
        while(p) {
            p=p->next;
            l1++;
        }
        while(q) {
            q=q->next;
            l2++;
        }
        p = headA, q = headB;
        if(l2>l1) {
            for(int i=0;i<l2-l1;i++)
                q=q->next;
        }
        else {
            for(int i=0;i<l1-l2;i++)
                p=p->next;            
        }
        while(p && q) {
            if(p==q)
                return p;
            p=p->next;
            q=q->next;
        }
        return NULL;
    }
};