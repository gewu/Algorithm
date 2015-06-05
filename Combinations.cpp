/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file Combinations.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/06/05 09:13:16
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<vector<int> > combine(int n, int k){
        vector<vector<int> > res;
        if (n <= 0)
            return res;

        vector<int> tmpres;
        help(1, n, k, res, tmpres);
        return res;

    }

    void help(int index, int n, int k , vector<vector<int> >& res, vector<int>& tmpres){
        if (tmpres.size() == k){
            res.push_back(tmpres);
            return ;
        }
        if (tmpres.size() > k)
            return ;
        for (int i = index; i <= n; i++){
            tmpres.push_back(i);
            help(i+1, n, k, res, tmpres);
            tmpres.pop_back();
        }
        
    }

};

int main(){
    Solution s;
    vector<vector<int> > v1 = s.combine(4,2);
    cout << v1.size()<<endl;
}




















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
