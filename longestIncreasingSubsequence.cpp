#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int lengthOfLIS(vector<int>& nums){
        if (nums.size() == 0)
            return 0;
        vector<int> flag(nums.size(), 1);
        int max_flag = 1;
        for (int i = nums.size()-2; i >= 0; i--){
            for (int j = i+1; j < nums.size(); j++){
                if (nums[i] < nums[j]){
                    if (max_flag < flag[j]+1)
                        max_flag = flag[j]+1;
                }
            }
            flag[i] = max_flag;
            max_flag = 1;
        }
        /*
        for (auto v : flag)
            cout << v << endl;
        */
        return *max_element(flag.begin(), flag.end());
    }
};

int main(){
    Solution s;
    vector<int> nums{10, 9, 2, 5, 3, 4};
    cout << s.lengthOfLIS(nums) << endl;
}
