/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file mergesort.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/04/01 19:42:25
 * @brief 
 *  
 **/

void mergearray(int a[], int first, int mid, int last, int temp[]){
    int i = first, j = mid+1;
    int m = mid, n = last;
    int k = 0;

    while (i <= m && j <= n){
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else 
            temp[k++] = a[j++];
    }
    while (i <= m)
        temp[k++] = a[i++];
    while (j <= n)
        temp[k++] = a[j++];

    for (int i = 0; i < k; i++)
        a[first+i] = temp[i];
}

void mergesort(int A[], int first, int high, int temp[]){
    if (first < high){
        int mid = (first+high)/2;
        mergesort(A, first, mid, temp);
        mergesort(A, mid+1, high, temp);
        mergearray(A, first, mid, high, temp);
    }
}





















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
