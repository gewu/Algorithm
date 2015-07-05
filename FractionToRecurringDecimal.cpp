/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file FractionToRecurringDecimal.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/07/05 09:57:39
 * @brief 
 *  
 **/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution{
public:
    string fractionToDecimal(int numerator, int denominator){
        ostringstream out;
        long long Numerator = numerator;
        long long Denominator = denominator;
        if (Denominator < 0){
            Denominator = -Denominator;
            Numerator = -Numerator;
        }
        if (Numerator < 0){
            Numerator = -Numerator;
            out << "-";
        }
        out<<(Numerator / Denominator);
        long long remainder = Numerator % Denominator;
        if (remainder == 0){
            return out.str();
        }
        out<<"." ;
        vector<int> save;
        map<int, int> have_flag;
        for (int i = 0; remainder && (have_flag.find(remainder) == have_flag.end()); ++i){
            have_flag[remainder] = i;
            remainder *= 10;
            save.push_back(remainder/Denominator);
            remainder %= Denominator;
        }
        if (remainder){
            for (int j = 0; j < have_flag[remainder];++j){
                out << save[j];
            }
            out <<"(";
            for (int j = have_flag[remainder]; j < save.size(); ++j){
                out << save[j];
            }
            out << ")";
        }
        else {
            for (int j = 0; j < save.size(); ++j) {
                out << save[j];
            }
        }
        return out.str();
    }
};

int main(){
    Solution s;
    string str = s.fractionToDecimal(1,3);
    cout << str << endl;

}



















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
