#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> BucketSort(int mySum[], int num){
    map<int, vector<int> > flag;

    for (int i = 0; i < num; i++)
        flag[mySum[i]].push_back(i);
    int maxt = 0;
    int begin = 0;
    int end = 0;

    for (map<int, vector<int> >::iterator iter = flag.begin(); iter != flag.end(); iter ++){
    
        int mySize = iter->second.size();
        if (iter->second[mySize-1] - iter->second[0] > maxt){
            maxt = iter->second[mySize-1] - iter->second[0];
            begin = iter->second[0];
            end = iter->second[mySize-1];
        }
    }

    vector<int> ret;
    ret.push_back(begin);
    ret.push_back(end);
    return ret;
}

void subArray(int A[], int n){
    if (n == 0)
        return ;
    int *sum = new int[n];

    sum[0] = A[0];
    for (int i = 1; i < n; i++)
        sum[i] = sum[i-1]+A[i];
    vector<int> ret = BucketSort(sum, n);
    for (int i = ret[0]; i < ret[1]; i++){
        cout << A[i] << " ";
    }
    cout << endl;

}

int main(){
    int A[100];
    int i = 0;
    int tmp;
    while (cin >> tmp)
        A[i++] = tmp;
    subArray(A, i);

}
