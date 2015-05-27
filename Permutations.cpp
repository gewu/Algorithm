/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file Permutations.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/05/24 16:15:53
 * @brief 
 *  
 **/

class Solution{
public:
    vector<vector<int> > permute(vector<int>& nums){
        vector<vector<int> > res;
        if (num.size() == 0)
            return res;
        vector<int> tmpres;
        permuteRecur(num, 0, res, tmpres);
        return res;
    }

    void permuteRecur(vector<int> &num, int index, vcetor<vector<int> >&res, vector<int>&tmpres){
        if (index == num.size()){
            res.push_back(tmpres);
            return;
        }
        for (int i = index; i < num.size(); i++){
            swap(num[index], num[i]);
            tmpres.push_back(num[index]);
            permuteRecur(num, index+1, res, tmpres);
            tmpres.pop_back();
            swap(num[index], num[i]);
        }

    } 
    
    
};

int main(){
    vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(3);
}






















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
