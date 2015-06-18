/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file LengthOfLastWord.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/06/18 09:12:47
 * @brief 
 *  
 **/
#include <iostream>
using namespace std;

class Solution{
public:
    int lengthOfLastWord(string s){
        if (s.length() <= 0)
            return 0;

        int index = s.length()-1;
        while (index >= 0){
            if (s[index] >= 'A' && s[index] <= 'z')
                break;
            --index;
        }
        int retLen = 0;
        for (; index >= 0; --index){
            if (s[index] == ' ')
                return retLen;
            if (s[index] >= 'A' && s[index] <= 'z')
                retLen++;
        }

        return retLen;

    }
};


int main(){
    string str("Hello World");
    Solution s;
    cout << s.lengthOfLastWord(str)<<endl;
}

















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
