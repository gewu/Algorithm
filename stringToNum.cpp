/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file stringToNum.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/07/15 11:43:17
 * @brief 
 *  
 **/

#include <iostream>
using namespace std;

int main(){
    string s = "1234 +";

    int i = 1;
    int k = i;
    while(s[k] >= '0' && s[k] <= '9'){
        k++;
    }

    string tmp(s, i, k-i);
    cout << tmp << endl;
}






















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
