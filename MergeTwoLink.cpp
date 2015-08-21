#include <iostream>

struct ListNode{
    int val;
    struct ListNode *next;
    ListNode (int x):
        val(x), next(NULL){}
};

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2){
        ListNode *p = pHead1;
        ListNode *q = pHead2;

        if (p == NULL && q == NULL)
            return NULL;
        
        if (p == NULL)
            return q;
        if (q == NULL)
            return p;

        ListNode *head = p->val > q->val? q:p;
        ListNode *k = head;
        if (k == p)
            p = p->next;
        if (k == q)
            q = q->next;

        while (p != NULL && q != NULL){
            if (p->val < q->val){
                k->next = p;
                p = p->next;
            }
            else{ 
                k->next = q;
                q = q->next;
            }
            k = k->next;
        }

        if (p != NULL){
            k->next = p;
        }

        if (q != NULL)
            k->next = q;
        
        return head;
    }

};


int main(){
    ListNode t1(1);
    ListNode t2(2);
    ListNode t3(3);
    ListNode t4(4);

    t1.next = &t2;
    t3.next = &t4;

    Solution s;
    ListNode* h = s.Merge(&t1, &t3);
    while (h != NULL){
        std::cout << h->val << " ";
        h = h->next;
    }
}
