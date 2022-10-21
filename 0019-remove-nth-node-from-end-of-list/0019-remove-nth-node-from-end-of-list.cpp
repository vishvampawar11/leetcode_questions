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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p1 = head, *p2 = NULL;
        for(int i=0;i<n-1;i++)
            p1=p1->next;
        while(p1 && p1->next) {
            if(!p2) p2 = head;
            else p2=p2->next;
            p1=p1->next;
        }
        if(!p2)
            head=head->next;
        else
            p2->next = p2->next->next;
        return head;
    }
};