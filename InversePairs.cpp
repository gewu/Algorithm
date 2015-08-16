#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int InversePairs(vector<int>& data){
        vector<int> tmp(data.size());
        long long  ret = InversePairsCore(data, tmp, 0, data.size()-1);
        return ret;
    }

    long long MergePairsBetweenArray(vector<int>& data, vector<int>& tmp, int start, int mid, int end){
        int i = start;
        int j = mid+1;
        int k = start;
        long long cnt = 0;

        while (i <= mid && j <= end){
            if (data[i] > data[j]){
                cnt += end-j+1;
                tmp[k++] = data[i++];
            }else {
                tmp[k++] = data[j++];
            }
        }

        while (i <= mid){
            tmp[k++] = data[i++];
        }
        while (j <= end){
            tmp[k++] = data[j++];
        }

        for (int i = start; i <= end; i++){
            data[i] = tmp[i];
        }
        return cnt;
    }

    long long InversePairsCore(vector<int>& data, vector<int>& tmp, int start, int end){
        long long cnt = 0;
        if (start < end){
            int mid = (start+end)/2;
            cnt += InversePairsCore(data, tmp, start, mid);
            cnt += InversePairsCore(data, tmp, mid+1, end);
            cnt += MergePairsBetweenArray(data, tmp, start, mid, end);
        }
        return cnt;
    }
};

int main(){

    int A[] = {4,3,2,1};
    vector<int> nums(&A[0], &A[4]);
    Solution s;
    cout << s.InversePairs(nums) << endl;
}
