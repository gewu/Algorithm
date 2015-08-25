#include <iostream>
#include <vector>
using namespace std;


void max_heapify(int *a, int i, int n){
    int j, temp;
    temp = a[i];
    j = 2*i;
    while (j <= n){
        if (j < n && a[j+1] > a[j])
            j++;
        if (temp > a[j])
            break;
        else if (temp < a[j]){
            a[j/2] = a[j];
            j = j*2;
        }
    }
    a[j/2] = temp;
    return ;
}

void headsort(int *a, int n){
    int i;
    for (i = n; i >= 2; i--){
        swap(a[i], a[1]);
        max_heapify(a, 1, i-1);
    }
}

void build_maxheap(int *a, int n){
    int i;
    for (int i = n/2; i >= 1; i++){
        max_heapify(a, i, n);
    }
}

int main(){


}
