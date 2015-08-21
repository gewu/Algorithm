#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    bool exist(vector<vector<char> >& board, string word){
        const int row = board.size();
        if (row == 0)
            return false;
        const int col = board[0].size();
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                if (board[i][j] == word[0] && dfs(i, j, word, 0, board))
                    return true;
            }
        }
        return false;

    }

    bool dfs(int row, int col, string &word, int index, vector<vector<char> > &board){
        if (index == word.size()-1)
            return true;
        char ctmp = board[row][col];
        board[row][col] = '#';

        if (row-1 >= 0 && board[row-1][col] == word[index+1])
            if (dfs(row-1, col, word, index+1, board))
                return true;

        if (row+1 < board.size() && board[row+1][col] == word[index+1])
            if (dfs(row+1, col, word, index+1, board))
                return true;

        if (col-1 >= 0 && board[row][col-1] == word[index+1])
            if (dfs(row, col-1, word, index+1, board))
                return true;

        if (col+1 < board[0].size() && board[row][col+1] == word[index+1])
            if (dfs(row, col+1, word, index+1, board))
                return true;

        board[row][col] = ctmp;
        return false;
    }
};

int main(){}
