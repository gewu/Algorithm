#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL){}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head){
        if (head == NULL)
            return head;
        ListNode *pre = head;
        ListNode *cur = head->next;
        while(cur != NULL){
            if (pre->val == cur->val)
                cur = cur->next;
            else {
                pre->next = cur;
                pre = cur;
                cur = cur->next;
            }
        }
        pre->next = cur;
        return head;
    }
};

int main(){
    ListNode pt1(1);
    ListNode pt2(1);
    ListNode pt3(2);
    ListNode pt4(3);
    pt1.next = &pt2;
    //pt2.next = &pt3;
    //pt3.next = &pt4;
    Solution solution;
    ListNode *ptr = NULL;
    ListNode *root = solution.deleteDuplicates(&pt1);
    while(root != NULL){
        cout << root -> val << " ";
        root = root ->next;
    }
}
