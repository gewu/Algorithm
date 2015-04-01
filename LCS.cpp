/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file LCS.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/03/31 09:22:02
 * @brief 
 *  substring should be continuous;  
 **/

#include <iostream>
#include <vector>
using namespace std;

const string LCS(const string& s1, const string s2){
    vector<int> arr(s1.length(), 0);       //the current line
    vector<int> prearr(s1.length(), 0);    // the pre line
    int pos = 0;
    int maxlen = 0;
    string stemp1("0");
    string stemp2("0");

    for (int i = 0; i < s2.length(); i ++){
       stemp1 = s2.substr(i, 1);
       for (int j = 0; j < s1.length(); j++){
            stemp2 = s1.substr(j,1);
            if (stemp1.compare(stemp2) == 0){
                if (j == 0)
                    arr[j] = 1;
                else{
                    arr[j] = prearr[j-1]+1;
                } 
                if (arr[j] > maxlen){
                    maxlen = arr[j];
                    pos = j;
                }
                    
            }
       }
       prearr.assign(arr.begin(), arr.end());
       /*cout << arr.size() << endl;
       vector<int>::iterator iter1 = arr.begin();
       vector<int>::iterator iter2 = prearr.begin();
       while(iter1 != arr.end()){
           cout << *iter1 << "," ;
           cout << "JJJJ" << endl;
           *iter2 = *iter1;
           ++iter1;
           ++iter2;
       }*/
    }
    string res = s1.substr(pos-maxlen+1, maxlen);
    return res;
}


int main(){

    string str1("ABCDEFG");
    string str2("BCDEK");
    string lcs = LCS(str1, str2);
    cout << lcs << endl;
    return 0;
}



















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
