/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file UniqueBinarySearchTrees.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/03/20 10:05:02
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int numTrees(int n){
        static vector<int> fn(n+1,0);
        fn[0] = 1;
        fn[1] = 1;
        for(int i = 2; i <=n ; i++){
            for (int k = 1; k <= i; ++k){
                fn[i] += fn[k-1]*fn[i-k];
            }
        }
        return fn[n];
    }

};

int main(){
    Solution solution;
    int n = solution.numTrees(6);
    cout << n << endl;
    return 1;
}





















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
