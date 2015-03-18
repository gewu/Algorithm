/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file HeapSort.c
 * @author gewu(com@baidu.com)
 * @date 2015/03/17 17:20:21
 * @brief 
 *  
 **/

#include <stdio.h>

void swap(int A[], int i, int j){
    int tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}

void sink(int A[], int k, int N){
    while (2*k <= N){
        int j = 2*k;
        if (j < N && A[j] < A[j+1]) 
            j++;
        if (!(A[k] < A[j]))
            break;
        swap(A, k, j);
        k = j;
    }
}

void heapsort(int A[], int N){
    int k = N/2;
    for (; k >= 1; k--)
        sink(A, k, N);
    while (N > 1)
    {
        swap(A, N--, 1);
        sink(A, 1, N);
    }
}

int main(){
    int A[] = {0,2,3,1,5,4};
    heapsort(A, 5);
    int i = 1;
    for (; i <= 5; i++)
        printf("%d ", A[i]);

}


/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
