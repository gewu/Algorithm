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

    int lengthOfLis2(const vector<int>& nums){
        vector<int> LIS;
        for (int i = 0; i < nums.size(); i++){
            if (LIS.size() == 0 || LIS[LIS.size()-1] < nums[i])
                LIS.push_back(nums[i]);
            else {
                int l = 0, r = LIS.size()-1;
                while (l < r){
                    int m = (l+r)/2;
                    if (LIS[m] >= nums[i]){
                        r = m;
                    }else {
                        l = m+1;
                    }
                }
                LIS[l] = nums[i];
            }
        }
        return LIS.size();
    }
};

int main(){
    Solution s;
    vector<int> nums{10, 9, 2, 5, 3, 4};
    cout << s.lengthOfLis2(nums) << endl;
}
