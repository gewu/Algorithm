/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file quicksort.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/04/01 13:43:37
 * @brief 
 *  
 **/


#include <iostream>
using namespace std;

int partition(int A[], int low, int high){
    int i = low;
    int j = high+1;
    int key = A[low];

    while (true){
        while (A[++i] < key){
            if (i == high)
                break;
        }
        while (A[--j] > key){
            if (j == low)
                break;
        }
        if (i >= j)
            break;
        swap(A[i], A[j]);
    }
    swap(A[low], A[j]);
    return j;
}

void quicksort(int A[], int lo, int hi){
    if (lo >= hi)
       return ;
    int j = partition(A, lo, hi);
    quicksort(A, lo, j-1);
    quicksort(A, j+1, hi); 

}
int sort(int A[], int len){
    quicksort(A, 0, len-1);
    return 1;
}

int main(){
    int A[] = {2,1,3,6,5};
    sort(A, 5);
    for (int i = 0; i < 5; i++)
        cout << A[i] << " "; 
}





/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
