/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file CountPrimes.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/06/11 09:29:11
 * @brief 
 *  
 **/
#include <iostream>
#include <math.h>
using namespace std;

class Solution{
public:
    int countPrimes(int n){
        int isPrime[n];
        for (int i = 2; i < n; i++){
            isPrime[i] = 1;
        }

        for (int i = 2; i*i < n; i++){
            if (isPrime[i] == 0)
                continue;
            for (int j = i*i; j < n; j += i){
                isPrime[j] = 0;
            }
        }
        int count = 0;
        for (int i = 2; i < n ; i++){
            if (isPrime[i] == 1)
                count++;
        }
        return count;
    }

    int countPrimes2(int n){
        if (n<=2)
            return 0;
        bool *p = new bool[n];
        memset(p, true, sizeof(bool)*n);

        for (int i = 2; i*i < n; i++){
            if (p[i]){
                for (int j = i*i; j < n; j+=i)
                    p[j] = false;
            }
        }
        int cnt = 0;
        for (int i = 2; i != n; i++){
            if (p[i])
                cnt++;
        }
        delete []p;
        return cnt;
    }
};

int main(){
    Solution s;
    cout << s.countPrimes(1500000) << endl;
    cout << s.countPrimes2(1500000) << endl;
    //cout << s.isPrime(999983) << endl;
}




















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
