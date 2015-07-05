/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file MultiplyStrings.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/07/05 20:16:33
 * @brief 
 *  
 **/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
public:
    string multiply(string num1, string num2){
        string ret(num1.length()+num2.length(), '0');
        int index1 = num1.size()-1;
        int index3 = ret.size()-1;
        for (; index1 >= 0; index1--){
            int index2 = num2.size()-1;
            int index3_copy = index3;
            int fac = 0;
            for (; index2 >= 0; index2--){
                int mul = (num1[index1]-'0')*(num2[index2]-'0');
                int result = 0;
                if (mul >= 10){
                    result = mul%10+fac+(ret[index3_copy]-'0');
                }else {
                    result = mul+fac+(ret[index3_copy]-'0');
                }

                if (result >= 10){
                    fac = result/10 + mul/10; 
                }else {
                    fac = mul/10;
                }
                ret[index3_copy] = result%10+'0';
                index3_copy--;
            }
            if (fac > 0){
                int tmp = ret[index3_copy] - '0';
                ret[index3_copy] = tmp+fac+'0';
            }
            --index3;
        }

        for (int i = 0; i < ret.size(); i++){
            if (ret[i] != '0'){
                return string(&ret[i], &ret[ret.size()]);
            }
        }
        return string("0");
    }
};

int main(){
    Solution s;
    string num1("999");
    string num2("999");
    string num3 = s.multiply(num1, num2);

    cout << num3 << endl;
}



















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
