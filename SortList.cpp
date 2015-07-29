#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

class Solution{
public:
    ListNode* sortList(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }       

        ListNode* fast = head;
        ListNode* slow = head;

        while (fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        fast = slow->next;
        slow->next = NULL;

        ListNode* p1 = sortList(head);
        ListNode* p2 = sortList(fast);

        return merge(p1, p2);
    }

    ListNode* merge(ListNode* list1, ListNode* list2){
        if (!list1){
            return list2;
        }else if (!list2){
            return list1;
        }

        ListNode dummy(0);
        ListNode* p = &dummy;

        while (list1 && list2){
            if (list1->val < list2->val){
                p->next = list1;
                list1 = list1->next;
            }else {
                p->next = list2;
                list2 = list2->next;
            }
            p = p->next;
        }

        if (list1){
            p->next = list1;
        }else if (list2){
            p->next = list2;
        }

        return dummy.next;
    }
};

int main(){
    ListNode t1(3);
    ListNode t2(2);
    ListNode t3(1);
    ListNode t4(4);
    t1.next = &t2;
    t2.next = &t3;
    t3.next = &t4;

    Solution s;
    ListNode *p = s.sortList(&t1);

    while (p != NULL){
        cout << p->val << " " << endl;
        p = p->next;
    }
    cout << endl;
}
