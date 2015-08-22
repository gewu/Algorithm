#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& condidates, int target){
        vector<vector<int> > res;
        vector<int> tmp;
        vector<int>::iterator it = condidates.begin();
        sort(condidates.begin(), condidates.end());
        help(condidates, it, target, tmp, res);
        return res;
    }

    void help(vector<int>& condidates, vector<int>::iterator it, int target, vector<int>& tmp, vector<vector<int> >& res){
        if (target == 0)
            res.push_back(tmp);
        if (target <= 0)
            return ;
    
        for (; it != condidates.end(); it++){
            tmp.push_back(*it);    
            help(condidates, it, target-(*it), tmp, res);
            tmp.pop_back();
        }   
    }
};

int main(){

    int A[] = {2,3,6,7};
    vector<int> nums(&A[0], &A[4]);
    Solution s;
    vector<vector<int> > res = s.combinationSum(nums, 7);

    for (int i = 0; i < res.size();i++){
        for (int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}

