#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

class Solution{
public:
    void deleteNode(ListNode* node){
        if (node == NULL)
            return ;
        node->val = node->next->val;
        node->next = node->next->next;
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
    s.deleteNode(&t3);
    for (ListNode *p = &t1; p != NULL; p = p->next){
        cout << p->val << " ";
    }
    cout << endl;
}



