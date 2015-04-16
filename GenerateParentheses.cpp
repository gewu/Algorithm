/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file GenerateParentheses.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/04/03 09:41:20
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<string> generateParenthesis(int n){
        vector<string> res;
        generate("", res, n, n);
        return res;
    }

    void generate(string tmpres, vector<string>& res, int l, int r){
        if (l > r)
            return ;
        if (l == 0 && r == 0){
            res.push_back(tmpres);
        }
        if (l > 0)
            generate(tmpres+"(", res, l-1, r);
        if (r > 0)
            generate(tmpres+")", res, l, r-1);

    }
};

int main(){
    Solution solution;
    vector<string> items = solution.generateParenthesis(1);
    cout << items.size();
    cout << items[0] << endl;

    //cout << items[1] << endl;
}



















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
