#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

class Solution{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        int flag = 0;
        if (l1 == NULL)
            return l2;
        ListNode* pre = NULL;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        while (p1 != NULL && p2 != NULL){
            p1->val += flag+p2->val;
            if (p1->val >= 10){
                flag = p1->val / 10;
                p1->val = p1->val % 10;
            }else {
                flag = 0;
            }
            pre = p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        if (p2 == NULL){
            if (p1 == NULL && flag != 0)
                pre->next = new ListNode(flag);
            if (p1 != NULL)
                dealFlag(p1, flag);
        }else {
            pre->next = p2;
            dealFlag(p2, flag); 
        }

        return l1;
    }
    
    void dealFlag(ListNode* pre, int flag){
        ListNode* tmp_pre = pre;
        while (pre != NULL && flag != 0){
            pre->val += flag;
            if (pre->val >= 10){
                flag = pre->val / 10;
                pre->val %= 10;
            }else {
                flag = 0;
            }
            tmp_pre = pre;
            pre = pre->next;
        }
        if (flag != 0){
            tmp_pre->next = new ListNode(flag);        
        }
    }
};

int main(){
    ListNode t1(9);
    ListNode t2(8);
    ListNode t3(3);

    ListNode t4(1);
    ListNode t5(3);
    ListNode t6(4);

    /*t1.next = &t2;
    t2.next = &t3;

    t4.next = &t5;
    t5.next = &t6;
    */

    Solution s;
    ListNode *ret = s.addTwoNumbers(&t1, &t4);
    while (ret != NULL){
        cout << ret->val << " " ;
        ret = ret->next;
    }
}
