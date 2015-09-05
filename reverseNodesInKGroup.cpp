#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

class Solution{
public:
    ListNode* reverseKGroup(ListNode* head, int k){
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *begin = head;
        ListNode *end = head;
        ListNode *p = head;
        int num = k;
        while (k != 0 && p != NULL){
            end = p;
            k--;
            p = p->next;
        }
        if (k != 0)
            return head;
        ListNode *ret = reverse(begin, end);
        k = num;

        while (p != NULL && k != 0){
            end = p;
            k--;
            p = p->next;
            if (k == 0){
                ListNode* temp_node = begin->next;
                begin->next = reverse(begin->next, end);
                begin = temp_node;
                k = num;
            }
        }
        return ret;
    }

    ListNode* reverse(ListNode* head, ListNode* end){
        ListNode *pre = end->next;
        ListNode *cur = head;
        ListNode *next = cur->next;
        while (cur != end){
            cur->next = pre;
            pre = cur;
            cur = next;
            next = cur->next;
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
    ListNode t5(5);

    t1.next = &t2;
    /*t2.next = &t3;
    t3.next = &t4;
    t4.next = &t5;*/

    Solution s;
    ListNode *p = s.reverseKGroup(&t1, 3);
    while (p != NULL){
        cout << p->val << " ";
        p = p->next;
    }
}
