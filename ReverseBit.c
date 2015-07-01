/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file ReverseBit.c
 * @author gewu(com@baidu.com)
 * @date 2015/07/01 10:13:42
 * @brief 
 *  
 **/


uint32_t reverseBits(uint32_t n){
    uint32_t result = 0;
    for (int i = 0; i < 32; i++){
        result <<= 1;
        if (n & 1)
            result |= 1;
        n >>= 1;
    }
    return result;
}





















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
