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
        vector<vector<int>> table(m, vector<int>(n,1));
        for (int i = 1; i < m; i++){
            for (int j = 1; j<n;j++){
                table[i][j] = table[i-1][j] + table[i][j-1];       
            }
        }
        return table[m-1][n-1];
    }
};

int main(){

    Solution solution;
    int val = solution.uniquepaths(3, 3);
    cout << val;
}






















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
