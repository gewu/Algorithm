/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file LongestCommonPrefix.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/07/22 09:07:22
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
public:
    string longestCommonPrefix(vector<string>& strs){
        if (strs.size() == 0)
            return "";
        if (strs.size() == 1 )
            return strs[0];

        string ret = strs[0];
        for (int i = 1; i < strs.size(); i++){
            ret = getCommonPrefix(ret, strs[i]);
        }
        return ret;
        
    }

    string getCommonPrefix(string str1, string str2){
        int n = str1.size() > str2.size() ? str2.size():str1.size();
        if (n == 0)
            return "";
        int i = 0;
        for (; i < n; i++){
            if (str1[i] != str2[i])
                break;
        }
        string ret(str1, 0, i);
        return ret;
    }
};

int main(){
    vector<string> strs;
    string s1("caa");
    string s2("");
    string s3("a");
    string s4("acb");

    strs.push_back(s1);
    strs.push_back(s2);
    strs.push_back(s3);
    strs.push_back(s4);
    Solution s;
    cout << s.longestCommonPrefix(strs) << endl;

}



















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
