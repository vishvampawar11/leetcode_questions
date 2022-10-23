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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || !head)
            return head;
        int n = 0;
        ListNode *curr = head, *prev = NULL;
        while(curr->next) {
            n++;
            curr = curr->next;
        }
        curr->next = head;
        n++;
        curr = head;
        k%=n;
        for(int i=0;i<n-k;i++) {
            prev = curr;
            curr = curr->next;
        }
        head = curr;
        prev->next = NULL;
        return head;
    }
};