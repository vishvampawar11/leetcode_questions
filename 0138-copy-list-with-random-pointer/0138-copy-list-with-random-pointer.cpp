/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return head;
        map<Node *, Node *> m;
        Node *newHead = new Node(head->val);
        Node *p = newHead;
        m[head] = newHead;
        while(head) {
            if(head->next) {
                if(m.find(head->next) != m.end())
                    p->next = m[head->next];
                else {
                    p->next = new Node(head->next->val);
                    m[head->next] = p->next;   
                }
            }
            if(head->random) {
                if(m.find(head->random) != m.end()) 
                    p->random = m[head->random];
                else {
                    p->random = new Node(head->random->val);
                    m[head->random] = p->random;  
                }
            }
            head = head->next;
            p = p->next;
        }
        return newHead;
    }
};