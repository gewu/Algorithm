#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<int> getRow(int rowIndex){
        vector<int> pre;
        vector<int> cur;
        pre.push_back(1);

        for (int i = 1; i <= rowIndex; i++){
            cur.push_back(pre[0]);
            for (int j = 1; j < pre.size(); j++){
                cur.push_back(pre[j]+pre[j-1]);
            }
            cur.push_back(pre.back());
            pre.clear();
            pre.swap(cur);
        }
        return pre;
    }
};

int main(){
    Solution s;
    vector<int> ret = s.getRow(3);
    for (int i = 0; i < ret.size(); i++){
        cout << ret[i] << " " ;
    }

}
