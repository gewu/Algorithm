/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file Numberof1.c
 * @author gewu(com@baidu.com)
 * @date 2015/03/16 17:43:48
 * @brief 
 *  
 **/

#include <stdio.h>

int NumberOf1(int n){
    int count = 0;
    unsigned int flag = 1;
    while(flag){
        if (n & flag)
            count ++;
        flag = flag << 1;
    }
    return count;
}

int main(){
    int num = 6;
    int result = NumberOf1(num);
    printf ("%d\n", result);
}




















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
