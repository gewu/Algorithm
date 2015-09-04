#include <iostream>
using namespace std;

struct RandomListNode{
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x):
        label(x), next(NULL), random(NULL){
            
        }
};

class Solution{
public:
    void outputLink(RandomListNode* head){
        while (head != NULL){
            cout << head->label << " ";
            head = head->next;
        }
        cout << endl;
    }

    RandomListNode* Clone(RandomListNode* pHead){
        RandomListNode* p = pHead;
        while (p != NULL){
            RandomListNode *t = new RandomListNode(p->label);
            t->next = p->next;
            p->next = t;
            p = t->next;
        }
        
        p = pHead;
        while (p != NULL){
            if (p->random != NULL){
                p->next->random = p->random->next;
            }   
            p = p->next->next;
        }

        p = pHead;
        RandomListNode* cl = pHead->next;
        RandomListNode* ret = cl;

        outputLink(pHead);
       
        while (p != NULL && cl->next != NULL){
            p->next = p->next->next;
            cl->next = cl->next->next;
            
            p = p->next;
            cl = cl->next;
        }
        p->next = p->next->next;
        outputLink(pHead);
        outputLink(ret);
        return ret;
    }
};


int main(){

    RandomListNode t1(1);
    RandomListNode t2(2);
    RandomListNode t3(3);

    t1.next = &t2;
    //t2.next = &t3;
    t2.random = &t1;
    Solution s;
    RandomListNode *p = s.Clone(&t1);
    cout << p->label << endl;
    cout << p->next->random->label << endl;

}
