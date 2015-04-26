/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file RemoveDuplicatesfromSortedArray.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/04/12 17:03:41
 * @brief 
 *  
 **/

#include <iostream>
using namespace std;

class Solution{
public:
    int removeDuplicates(int A[], int n){
        if (n < 2)
            return n;
        int pre = 0;
        int cur = 0;
        for (; cur < n; ++cur){
            if (A[pre] == A[cur])
                continue;
            A[++pre] = A[cur];
        }
        return ++pre;
    }
};

int main(){
    int A[] = {1,1,2};
    Solution solution;
    int length = solution.removeDuplicates(A, 3);
    cout << length;
}





















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
