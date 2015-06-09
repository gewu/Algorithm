/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file PascalTriangle.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/06/08 11:47:26
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<vector<int> > generate(int numRows){
        vector<vector<int> > res;
        vector<int> tmpres;
        if (numRows < 0)
            return res;
        tmpres.push_back(1);
        res.push_back(tmpres);
        tmpres.clear();
        int m = 0;
        int n = 0;

        for (int i = 1; i < numRows; i++){
            for (int j = 0; j < i+1; j++){
                
                m = j-1<0 ? 0 : res[i-1][j-1];
                n = j<res[i-1].size()? res[i-1][j]:0;
                tmpres.push_back(m+n);
            }
            res.push_back(tmpres);
            tmpres.clear();
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int> > res = s.generate(2);
    cout << res[1].size() << endl;

    for (int i = 0; i < res[1].size(); i++){
        cout << res[1][i] << " " ;
    }
}




















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
