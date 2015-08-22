#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution{
public:
    vector<vector<int> > combinationSum3(vector<int>& candidates, int target){
        vector<int> temp;
        set<vector<int> > res;
        sort(candidates.begin(), candidates.end());

        vector<int>:: iterator it = candidates.begin();

        help(candidates, it, target, temp, res);
        vector<vector<int> > ret(res.begin(), res.end());
        return ret;
        
    }

    void help(vector<int>& candidates, vector<int>::iterator it, int target, vector<int>& temp, set<vector<int> >& res){
        if (target == 0){
                res.insert(temp);
        } 
        
        if (target <= 0){
            return ;
        }

        for (; it != candidates.end(); it++){
                temp.push_back(*it);
                help(candidates, it+1, target-(*it), temp, res);
                temp.pop_back();
        }
    }
};


int main(){

    int A[] = {10, 1, 2, 7, 6, 1, 5};
    vector<int> nums(&A[0], &A[7]);
    Solution s;
    vector<vector<int> > res = s.combinationSum3(nums, 8);
    for (int i = 0; i < res.size(); i++){
        for (int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}
