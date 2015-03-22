/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file MajorityElement.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/03/21 16:00:38
 * @brief 
 *  
 **/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution{
public:
    int majorityElement(vector<int> &num){
        map<int, int> nummap;
        vector<int>::iterator iter = num.begin();
        for (; iter != num.end(); iter++){
            if (nummap.find(*iter) != nummap.end()){
                nummap[*iter]++;
                if (nummap[*iter] > num.size()/2)
                    return *iter;
            }
            else
                nummap[*iter] = 1;

        }
        return -1;        
    }
};

int main(){
    vector<int> numt;
    numt.push_back(2);
    numt.push_back(3);
    numt.push_back(2);
    Solution solution;
    int val = solution.majorityElement(numt);
    cout << val << endl;

}





















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
