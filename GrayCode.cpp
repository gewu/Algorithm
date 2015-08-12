#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<int> grayCode(int n){
        vector<int> greySeq;
        if (n < 0)
            return greySeq;
        greySeq.push_back(0);
        int inc = 1;
        for (int i = 1; i <= n; i++){
            for (int j = greySeq.size()-1; j>=0; j--)
                greySeq.push_back(greySeq[j]+inc);
            inc <<= 1;
        }
        return greySeq;
    }
};

int main(){
    Solution s;
    vector<int> re = s.grayCode(3);
    for (int i = 0; i < re.size(); i++){
        cout << re[i] << " ";
    }
    cout << endl;
}
