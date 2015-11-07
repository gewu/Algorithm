#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    void moveZeroes(vector<int>& nums){
        int n = nums.size();
        int index = 0;
        for (int i = 0; i < n; i++){
            if (nums[i] == 0)
                continue;
            nums[index++] = nums[i];
        }

        for (int i = index; i < n; i++){
            nums[i] = 0;
        }
    }
};

int main(){
    int A[] = {0, 1, 0, 3, 12};
    vector<int> nums(&A[0], &A[5]);
    Solution s;
    s.moveZeroes(nums);
    for (int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
}

