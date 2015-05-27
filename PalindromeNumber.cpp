/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file PalindromeNumber.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/05/26 21:02:16
 * @brief 
 *  
 **/

class Soultion{
piublic:
    bool isPalindrome(int x){
        int temp = x;
        int reverse = 0;

        while (temp != 0){
            reverse = reverse*10;
            reverse = reverse + temp%10;
            temp = temp /10;
        }

        return (n == reverse)
    }
};





















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
