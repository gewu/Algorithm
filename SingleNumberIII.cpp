#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums){
        int rXor = nums[0];

        for (int i = 1; i < nums.size(); i++){
            rXor ^= nums[i];
        }

        int ret = rXor & (~(rXor-1));

        int num1 = 0;
        int num2 = 0;
        for (int i = 0; i < nums.size(); i++){
            if ((nums[i]&ret) == 0){
                num1 ^= nums[i];
            }else {
                num2 ^= nums[i];
            }
        }
        int A[] = {num1, num2};
        return vector<int>(&A[0], &A[2]);
    }
};

int main(){
    int A[] = {1,2,1,3};
    vector<int> num(&A[0], &A[4]);
    Solution s;
    vector<int> res = s.singleNumber(num);
    for (int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    
}


