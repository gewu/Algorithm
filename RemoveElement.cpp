/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file RemoveElement.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/03/31 08:52:42
 * @brief 
 *  
 **/

#include <iostream>
using namespace std;

class Solution{
public:
    int removeElement(int A[], int n, int elem){
        int length = 0;
        int *pn = A;
        for (int i = 0; i <= n-1; i++){
            if (A[i] == elem)
                continue;
            *pn = A[i];
            ++pn;
            ++length;
        }
        return length;
    }
};

int main(){
    int num[] = {2,1,3,4,5,4};
    Solution solution;
    int val = solution.removeElement(num, 6, 4);
    cout << val;
}





















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
