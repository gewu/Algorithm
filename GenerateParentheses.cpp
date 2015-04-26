<<<<<<< HEAD
/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file GenerateParentheses.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/04/03 09:41:20
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>
=======
#include <iostream>
#include <vector>

>>>>>>> 9c07f3fa9759aaf5e23e8f8dfe94dc3dc55f3268
using namespace std;

class Solution{
public:
    vector<string> generateParenthesis(int n){
<<<<<<< HEAD
        vector<string> res;
        generate("", res, n, n);
        return res;
    }

    void generate(string tmpres, vector<string>& res, int l, int r){
        if (l > r)
            return ;
        if (l == 0 && r == 0){
            res.push_back(tmpres);
        }
        if (l > 0)
            generate(tmpres+"(", res, l-1, r);
        if (r > 0)
            generate(tmpres+")", res, l, r-1);

=======
        vector<string> items;
        generate(items, "", n, n);
        return items;
    }

    void generate(vector<string>& items, string item, int l, int r){
        if (l < r)
            return ;
        if (l == 0 && r == 0)
            items.push_back(item);
        if (l > 0)
            generate(items, item+")", l-1, r);
        if (r > 0)
            generate(items, item+"(", l, r-1);
>>>>>>> 9c07f3fa9759aaf5e23e8f8dfe94dc3dc55f3268
    }
};

int main(){
    Solution solution;
<<<<<<< HEAD
    vector<string> items = solution.generateParenthesis(1);
    cout << items.size();
    cout << items[0] << endl;

    //cout << items[1] << endl;
}



















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
=======
    vector<string> items = solution.generateParenthesis(3);
    cout << items.size() << endl;
    cout << items[1] << endl;
}
>>>>>>> 9c07f3fa9759aaf5e23e8f8dfe94dc3dc55f3268
