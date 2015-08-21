#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n){
        ListNode *pre = NULL;
        ListNode *cur = head;
        ListNode *next = head->next;


        for (int i = 1; i < m && next != NULL; i++){
            pre = cur;
            cur = next;
            next = next->next;
        }
        ListNode *tmpPre = pre;
        ListNode *tmpPost = cur;

        for (int i = m; i < n && next != NULL; i++){
            cur->next = pre;
            pre = cur;
            cur = next;
            next = next->next;
        }

        cur->next = pre;
        tmpPost->next = next;
        if (tmpPre != NULL){
            tmpPre->next = cur;
        }

        if (m == 1)
            return cur;
        return head;
    }

};


int main(){
    /*
    ListNode t1(1);
    ListNode t2(2);
    ListNode t3(3);
    ListNode t4(4);
    ListNode t5(5);
    */

    ListNode t1(1);
    ListNode t2(2);
    t1.next = &t2;

    Solution s;
    ListNode *p = s.reverseBetween(&t1, 1, 2);
    while (p != NULL){
        cout << p->val << " ";
        p = p->next;
    }
    
}
