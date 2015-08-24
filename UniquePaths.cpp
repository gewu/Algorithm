/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file UniquePaths.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/03/26 09:14:17
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int uniquepaths(int m, int n){
        if (m <0 || n < 0)
            return 0;
        if (m == 1 || n == 1)
            return 1;
        return uniquepaths(m, n-1) + uniquepaths(m-1,n);
    }

    int uniquePaths(int m, int n){
        vector<vector<int> > table(m, vector<int>(n,1));
        for (int i = 1; i < m; i++){
            for (int j = 1; j<n;j++){
                table[i][j] = table[i-1][j] + table[i][j-1];       
            }
        }
        return table[m-1][n-1];
    }

    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid){
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        cout << m << endl;
        if (m <= 0 || n <= 0)
            return 0;
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1)
            return 0;

        vector<vector<int> > table(m, vector<int>(n, 1));
        for (int i = 1; i < n; i++){
            if (obstacleGrid[0][i] == 1)
                table[0][i] = 0;
            else 
                table[0][i] = table[0][i-1];
        }

        for (int i = 1; i < m; i++){
            if (obstacleGrid[i][0] == 1)
                table[i][0] = 0;
            else 
                table[i][0] = table[i-1][0];
        }

        for (int i = 1; i < m; i++){
            for (int j = 1; j < n; j++){
                if (obstacleGrid[i][j] == 1){
                    table[i][j] = 0;
                }else {
                    table[i][j] = table[i-1][j] + table[i][j-1];
                }
            }
        }

        return table[m-1][n-1];
    }

    int help(vector<vector<int> >&obstacleGrid, int m, int n){
        if (m <= 0 || n <= 0)
            return 0;
        if (m == 1 || n == 1)
            return 1;
        if (obstacleGrid[m-1][n] == 0 && obstacleGrid[m][n-1] == 0)
            return help(obstacleGrid, m-1, n) + help(obstacleGrid, m, n-1);
        else if (obstacleGrid[m-1][n] == 0)
            return help(obstacleGrid, m-1, n);
        else if (obstacleGrid[m][n-1] == 0)
            return help(obstacleGrid, m, n-1);
        return 0;
    }
};

int main(){

    vector<vector<int> > ret;
    for (int i = 0; i < 20; i++){
        vector<int> tmp(1,0);
        ret.push_back(tmp);
    }

    cout << ret[5][0] << endl;

    Solution solution;
    int val = solution.uniquePathsWithObstacles(ret);
    cout << val << endl;
}






















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
