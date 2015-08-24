#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int missingNumber(vector<int>& nums){
        int a = 0;
        for (int i = 1; i <= nums.size(); i++){
            a ^= i;
        }
        for (int i = 0; i < nums.size(); i++){
            a ^= nums[i];
        }
        return a;
    }
};

int main(){
    int A[] = {2,1};
    vector<int> nums(&A[0], &A[2]);
    Solution s;

    cout << s.missingNumber(nums) << endl;
}
