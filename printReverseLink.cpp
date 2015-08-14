#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    struct ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

class Solution{
public:
    vector<int> printListFromTailTohead(struct ListNode* head){
        vector<int> tmp;
        ListNode *p = head;
        if (head == NULL)
            return tmp;
        while (p != NULL){
            tmp.push_back(p->val);
            p = p->next;
        }
        vector<int> ret;
        for (int j = tmp.size()-1; j>=0;j--){
            ret.push_back(tmp[j]);
        }
        return ret;
    }

    void printReverseLink(struct ListNode* head){
        if (head->next != NULL)
            printReverseLink(head->next);
        if (head != NULL)
            cout << head->val << " ";
    }
};

int main(){
    ListNode t1(1);
    ListNode t2(2);
    ListNode t3(3);
    t1.next = &t2;
    t2.next = &t3;
    Solution s;
    s.printReverseLink(&t1);
    cout << endl;
    /*
    vector<int> ret = s.printListFromTailTohead(&t1);
    for (int i = 0; i < ret.size(); i++){
        cout << ret[i] << " ";
    }
    cout << endl;
    */

}
