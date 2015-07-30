#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int trap(vector<int>& A){
        if (A.size() < 2)
            return 0;
        int n = A.size();
        vector<int> maxL(A.size(), 0);
        vector<int> maxR(A.size(), 0);
        int max = A[0];
        for (int i = 1; i<n-1; i++){
            maxL[i] = max;
            if (max < A[i])
                max = A[i];
        }
        max = A[n-1];
        int ctrap = 0;
        int ttrap = 0;

        for (int i = n-2; i>0;i--){
            maxR[i] = max;
            ctrap = min(maxL[i], maxR[i])-A[i];
            if (ctrap>0)
                ttrap += ctrap;
            if (max < A[i])
                max = A[i];
        }
        return ttrap;
    }
};

int main(){
    int A[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> nums(&A[0], &A[12]);
    Solution s;
    cout << s.trap(nums) << endl;
}
