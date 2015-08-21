#include <iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x):
        val(x), next(NULL){}
};

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode *slow = pListHead;
        ListNode *fast = pListHead;

        if (fast == NULL)
            return NULL;

        int i = k;
        for (; i > 0 && fast != NULL; i--){
            fast = fast->next;
        }

        if (i > 0)
            return NULL;

        while (fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
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
    cout << s.FindKthToTail(&t1, 6) << endl;

}
