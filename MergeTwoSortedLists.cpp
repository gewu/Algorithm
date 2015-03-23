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
	ListNode root(0);
	root.next = l1;
	ListNode *pln1 = &root;
        ListNode *pln2 = l2;
        ListNode *padd = NULL;
        while (pln1->next != NULL && pln2 != NULL){
            if (pln1->next->val > pln2->val){
	    	padd = pln2;
		pln2 = pln2->next;
		padd->next = pln1->next;
		pln1->next = padd;
	    }
	    else {
	    	pln1 = pln1->next;
	    }    
        }
	if (pln1->next == NULL)
		pln1->next = pln2;
	return root.next;
    }
};

int main(){
	ListNode l1(1);
	ListNode l2(3);
	ListNode l3(5);
	l1.next = &l2;
	l2.next = &l3;

	ListNode n1(2);
	ListNode n2(4);
	ListNode n3(6);
	n1.next = &n2;
	n2.next = &n3;
	
	Solution solution;
	ListNode *head = solution.mergeTwoLists(&l1, &n1);
	while(head != NULL){
		cout << head->val << " ";
		head = head->next;
	}
}
