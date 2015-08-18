#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int maxProduct(vector<int>& nums){
        if (nums.size() <= 0)
            return 0;
        int ret, curMax, curMin;
        ret = curMax = curMin = nums[0];
        for (int i = 1; i < nums.size();i++){
            int temp = curMax; 
            curMax = max(max(curMax*nums[i], curMin*nums[i]), nums[i]);
            curMin = min(min(temp*nums[i], curMin*nums[i]), nums[i]);
            ret = max(ret, curMax);
        }
        return ret;
    }
};


int main(){
    int A[] = {2,3,-2,4};
    vector<int> nums(&A[0], &A[4]);
    Solution s;
    cout << s.maxProduct(nums) << endl;

}
