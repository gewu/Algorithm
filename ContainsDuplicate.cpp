/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file ContainsDuplicate.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/05/29 09:28:38
 * @brief 
 *  
 **/

#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution{
public:
    bool containsDuplicate(vector<int>& nums){
        map<int, int> temp;
        cout << "nums:" << nums.size();
        for (int i = 0; i < nums.size(); i++){
            if (temp.find(nums[i]) == temp.end()){
                cout << "aaa";
                temp.insert(pair<int, int>(nums[i], 1));
            }
            else{ 
                ++temp[nums[i]];
            }
        }

        map<int,int>::iterator it = temp.begin();
        for (; it != temp.end(); it++){
            cout<< it->second<<endl;
            if (it->second > 1)
                return true;
        }
        return false;
    }
};

int main(){
    int ns[] = {0,0};
    vector<int> nums(&ns[0], &ns[2]); 
    
    Solution s;
    cout << s.containsDuplicate(nums);
}



















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
