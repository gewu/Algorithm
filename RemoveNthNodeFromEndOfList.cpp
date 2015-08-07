#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){};
};

class Solution{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n){
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast-next!=NULL && n>0){
            fast = fast->next;
            n--;
        }

        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        
        if (slow->next != NULL){
            slow->next = slow->next->next;
        }

        return head;
    }

};


int main(){
    ListNode t1(1);
    ListNode t2(2);
    ListNode t3(3);
    ListNode t4(4);
    ListNode t5(5);
    t1.next = &t2;
    t2.next = &t3;
    t3.next = &t4;
    t4.next = &t5;

    Solution s;
    ListNode* head = s.removeNthFromEnd(&t1, 2);
    while (head != NULL){
        cout << head->val << " " ;
        head = head->next;
    }
    cout << endl;
}
