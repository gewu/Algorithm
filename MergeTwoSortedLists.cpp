#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

class Solution{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2){
        ListNode *pln1 = l1;
        ListNode *pln2 = l2;
        ListNode *padd = NULL;
        while (pln1 != NULL && pln2 != NULL){
            if (pln1->val < pln2->val)
                pln1->next = pln2;
                
        }
    }
};
