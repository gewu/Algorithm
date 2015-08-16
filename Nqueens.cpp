#include <iostream>
#include <vector>
using namespace std;

class Solution{
    vector<int> res;
public:
    int totalNQueens(int n){
        vector<int> queens(n, -1);
        help(queens, 0);
        return res.size();
    }

    void help(vector<int>& queens, int row){
        int n = queens.size();
        if (row == n){
            res.push_back(1);                     
            return;
        }

        for (int col = 0; col < n; col++){
            if (check(queens, row, col)){
                queens[row] = col;
                help(queens, row+1);
            }
        }
    }

    bool check(vector<int>& queens, int row, int col){
        for (int  i = 0; i < row; i++){
            if (queens[i] == col || abs(row-i) == abs(col - queens[i]))
                return false;
        }
        return true;
    }
};


int main(){

    Solution s;
    cout << s.totalNQueens(4) << endl;
}
