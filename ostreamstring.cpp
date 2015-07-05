/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file ostreamstring.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/07/05 11:40:31
 * @brief 
 *  
 **/

#include <sstream>
#include <iostream>
#include <string>

using namespace std;

int main(){
    ostringstream ostr;
    ostr << "jhhhhh" << endl;
    ostr << 56 << endl;
    string s = ostr.str();
    cout << s << endl;
}





















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
