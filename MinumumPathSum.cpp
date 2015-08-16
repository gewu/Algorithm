#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> >& grid){
        if (grid.size() == 0)
            return 0;
        int row = grid.size();
        int col = grid[0].size();
        int Min[row][col];
        Min[0][0] = grid[0][0];
        for (int i = 1; i < row; i++){
            Min[i][0] = Min[i-1][0] + grid[i][0];
        }

        for (int i = 1; i < col; i++){
            Min[0][i] = Min[0][i-1] + grid[0][i];
        }

        for (int i = 1; i < row; i++){
            for (int j = 1; j < col; j++){
                Min[i][j] = min(Min[i-1][j], Min[i][j-1]) + grid[i][j];
            }
        }
        return Min[row-1][col-1];
    }
};

int main(){
    vector<vector<int> > res;
    vector<int> tmp1;
    vector<int> tmp2;
    tmp1.push_back(1);
    tmp1.push_back(2);
    tmp2.push_back(3);
    tmp2.push_back(4);

    res.push_back(tmp1);
    res.push_back(tmp2);

    Solution s;
    cout << s.minPathSum(res) << endl;
}
