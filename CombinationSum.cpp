#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<vector<int> > combinationSum3(int k, int n){
        vector<vector<int> > result;
        vector<int > item;
        help(result, item, 0, k, n);
        return result;
    } 

    void help(vector<vector<int> > &result, vector<int>& item, int max, int k, int left){
        if (item.size() == k && left == 0){
            result.push_back(item);
            return ;
        }

        for (int i = max+1; i <= 9 && i <= left; i++){
            item.push_back(i);
            help(result, item, i, k, left-i);
            item.pop_back();
        }
    }
};

int main(){

    Solution s;
    vector<vector<int> >res = s.combinationSum3(3,9);
    for (int i = 0 ; i < res.size() ;i++){
        for (int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}
