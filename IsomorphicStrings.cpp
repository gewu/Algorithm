/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file IsomorphicStrings.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/07/15 15:08:22
 * @brief 
 *  
 **/

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

class Solution{
public:
    bool isIsomorphic(string s, string t){
        if (s.size() != t.size())
            return false;
        map<char, char>flag;
        map<char, char>flag2;
        for (int i = 0; i < s.size(); i++){
            if (flag.find(s[i]) == flag.end()){
                flag[s[i]] = t[i];        
            }else if (flag[s[i]] != t[i]){
                    return false;
                }
        }
        for (int i = 0; i < s.size(); i++){
            if (flag2.find(t[i]) == flag2.end()){
                flag2[t[i]] = s[i];        
            }else if (flag2[t[i]] != s[i]){
                    return false;
                }
        }
        return true;

    }
};

int main(){
    Solution s;
    string t1 = "ab";
    string t2 = "aa";

    cout << s.isIsomorphic(t1, t2) << endl;
}




















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
