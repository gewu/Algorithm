#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<int> productExceptSelf(vector<int>& nums){
        int len = nums.size();
        vector<int> res(nums.size(), 1);
        for (int i = 1;i < nums.size(); i++){
            res[i] = nums[i-1]*res[i-1];
        }
        int temp = 1;
        for (int i = nums.size()-2; i>=0;i--){
           temp = nums[i+1]*temp;
           res[i] *= temp;
        }
        return res;
    }
};

int main(){
    int A[] = {1,2,3,4};
    vector<int> nums(&A[0], &A[4]);
    Solution s;
    vector<int> ret = s.productExceptSelf(nums);
    for (int i = 0; i<nums.size(); i++){
        cout << ret[i] << " ";
    }
    cout << endl;
}
