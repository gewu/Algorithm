#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<vector<int> > generateMatrix(int n){
        vector<vector<int> > ret(n, vector<int>(n, 0));
        int nlvl = n/2;
        int val = 1;
        for (int i = 0; i < nlvl ; i++){
            int last = n-1-i;
            for (int j = i; j < last; j++)
                ret[i][j] = val++;
            for (int j = i; j < last; j++)
                ret[j][last] = val++;
            for (int j = last; j > i; j--)
                ret[last][j] = val++;
            for (int j = last; j > i; j--)
                ret[j][i] = val++;
        }
        if (n%2 == 1)
            ret[n/2][n/2] = val;
        return ret;
    }
};

int main(){

    Solution s;
    vector<vector<int> > ret = s.generateMatrix(5);
    
}
