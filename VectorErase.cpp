/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file VectorErase.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/03/22 10:44:53
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> myvec;
    myvec.push_back(1);
    myvec.push_back(3);
    myvec.push_back(2);
    vector<int>::iterator iter = myvec.begin();
    ++iter;
    vector<int>::iterator iter2 = iter;
    //myvec.erase(iter);
    //iter2 = myvec.erase(iter2);
    iter = iter2++;
    cout << *iter << " " << *iter2 << endl;

}
























/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
