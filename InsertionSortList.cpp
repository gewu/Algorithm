#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

class Solution{
public:
    ListNode* insertionSortList(ListNode* head){
        ListNode* cur = head;
        if (cur == NULL || cur->next == NULL)
            return head;

        ListNode fakeHead(1);
        fakeHead.next = head;
        ListNode* next = head->next;

        while (next != NULL){
            if (cur->val <= next->val){
                cur = cur->next;
                next = cur->next;
                continue;
            }
            ListNode* p = &fakeHead;
            while (p->next != next){
                if (p->next->val > next->val){
                    cur->next = next->next;
                    next->next = p->next;
                    p->next = next;
                    break;
                }
                p = p->next;
            }
            if (p->next == next && p->next != NULL){
                cur = p->next;
            }
            next = cur->next;
        }
        
        return fakeHead.next;
    }
};

int main(){
    ListNode t1(6);
    ListNode t2(5);
    ListNode t3(8);
    ListNode t4(2);
    t1.next = &t2;
    t2.next = &t3;
    t3.next = &t4;

    Solution s;
    ListNode* head = s.insertionSortList(&t1);
    while (head != NULL){
        cout << head->val << " ";
        head = head->next;
    }

}
