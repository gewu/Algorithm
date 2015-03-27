/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file SortClors.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/03/26 20:36:46
 * @brief 
 *  
 **/

#include <iostream>
using namespace std;
class Solution{
public:
    void sortColors(int A[], int n){
        int count0 = 0;
        int count1 = 0;
        int count2 = 0;
        for (int i = 0; i < n; i++){
            if (A[i] == 0)
                ++count0;
            if (A[i] == 1)
                ++count1;
            if (A[i] == 2)
                ++count2;

            for (int i = 0; i < count0; i++)
                A[i] = 0;
            for (int j = count0; j < count0+count1; j++)
                A[j] = 1;
            for (int k = count0+count1; k < count0+count1+count2; k++)
                A[k] = 2;
        }
    }
};

int main(){

}



















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
