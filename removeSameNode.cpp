#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){}
};

class Solution{
public:
    ListNode* deleteDuplicates(ListNode* head){
        ListNode* p = head;
        ListNode* pre = head;
        if (p == NULL || p->next == NULL)
            return p;
        p = p->next;
        while (p != NULL){
            if (pre->val == p->val){
                pre->next = p->next;
                p->next = NULL;
                p = pre->next;
            }else {
                pre = p;
                p = p->next;
            }
        }
        return head;
    }
};

int main(){
    ListNode t1(1);
    ListNode t2(1);
    ListNode t3(2);
    ListNode t4(3);
    ListNode t5(3);
    ListNode t6(7);

    t1.next = &t2;
    t2.next = &t3;
    t3.next = &t4;
    t4.next = &t5;
    t5.next = &t6;
    Solution s;
    ListNode* p = s.deleteDuplicates(&t1);

    while (p != NULL){
        cout << p->val << " ";
        p = p->next;
    }
}


