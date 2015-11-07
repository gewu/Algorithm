/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file BasicCalculator.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/07/15 09:27:38
 * @brief 
 *  
 **/

#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution{
public:
    int calculate(string s){
        stack<char> op;
        stack<int> nums;
        stringstream ss;

        for (int i = 0; i<s.size(); i++){
            if (s[i] == ' ')
                continue;

            if (s[i] >= '0' && s[i] <= '9'){
                int k = i;
                while (s[k] >= '0' && s[k] <= '9'){
                    k++;
                }    
                string tmps(s, i, k-i);
                ss << tmps;
                int num = 0;
                ss >> num;
                ss.clear();
                ss.str("");
                nums.push(num);
                i = k-1;
                continue;
            }
            else {
                if (op.empty()||s[i] == '('){
                    op.push(s[i]);
                    continue;
                }else if (op.top() == '('){
                    if (s[i] == ')')
                        op.pop();
                    else 
                        op.push(s[i]);
                    continue;
                }else if (s[i] == ')'){
                    while (op.top() != '('){
                        int b = nums.top();
                        nums.pop();
                        int a = nums.top();
                        nums.pop();
                        char c = op.top();
                        op.pop();
                        nums.push(cal(a, b, c));
                    }
                    op.pop();
                }else if ((s[i] == '*' || s[i] == '/') && (op.top() == '+' || op.top() == '-')){
                    char opt = s[i++];
                    while (s[i] == ' '){
                        i++;
                    }
                    int k = i;
                    while (s[k] >= '0' && s[k] <= '9'){
                        k++;
                    }

                    string tmps(s, i, k-i);
                    ss << tmps;
                    int a = nums.top();
                    nums.pop();
                    int b = 0;
                    ss >> b;
                    ss.clear();
                    ss.str("");
                    i = k-1;
                    nums.push(cal(a,b,opt));
                }else {
                    char opt = op.top();
                    op.pop();
                    int b = nums.top();
                    nums.pop();
                    int a = nums.top();
                    nums.pop();
                    nums.push(cal(a,b,opt));
                    op.push(s[i]);
                }
            }

        }

        if (!op.empty()){
            char opt = op.top();
            int b = nums.top();
            nums.pop();
            int a = nums.top();
            nums.pop();
            return cal(a, b, opt);
        }
        return nums.top();
    }

    int cal(int a, int b, char op){
        switch(op){
            case '+':
                return a+b;
            case '-':
                return a-b;
            case '*':
                return a*b;
            case '/':
                if (b == 0)
                    return 0;
                return a/b;
        }
        return 0;
    }

};

int main(){
    //string test = "3+5/ 2";
    vector<string> test;
    string tmp;
    for (int i = 0; i < 4; i++){
        cin >> tmp;
        test.push_back(tmp);
    }
    Solution s;
    for (int i = 0; i < test.size(); i++){
        cout << s.calculate(test[i]) << endl;
    }

}



















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
