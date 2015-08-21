#include <iostream>
using namespace std;

struct ListNode{
    int val;
    struct ListNode *next;
    ListNode (int x):
        val (x), next(NULL){}
};

class Solution {
public:
    ListNode* ReverseList(ListNode* phead){
        if (phead == NULL)
            return NULL;
        ListNode* pre = NULL;
        ListNode* cur = phead;
        ListNode* next = phead->next;

        while (next != NULL){
            cur->next = pre;
            pre = cur;
            cur = next;
            next = next->next;
        }
        cur->next = pre;
        return cur;
    }
};


int main(){
    ListNode t1(1);
    ListNode t2(2);
    ListNode t3(3);
    ListNode t4(4);

    t1.next = &t2;
    t2.next = &t3;
    t3.next = &t4;
    
    Solution s;
    ListNode* p = s.ReverseList(&t1);
    while (p != NULL){
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

