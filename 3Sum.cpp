#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution{
public:
    vector<vector<int> > threeSum(vector<int>& nums){
        sort(nums.begin(), nums.end());
        vector<vector<int> > ret;
        for (int i = 0; i < nums.size(); i++){
            int target = 0-nums[i];
            int start = i+1, end = nums.size()-1;
            while (start < end){
                if (nums[start] + nums[end] == target){
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[start]);
                    tmp.push_back(nums[end]);
                    ret.push_back(tmp);
                    start++;
                    end--;
                    while (start < end && nums[start] == nums[start-1]){
                        start++;
                    }
                    while (start < end && nums[end] == nums[end+1]){
                        end--;
                    }
                }else if (nums[start]+nums[end] < target){
                    start++;
                }else {
                    end--;
                }
            }
            if (i < nums.size()){
                while (nums[i] == nums[i+1])
                    i++;
            }

        }
        return ret;

    }
};

int main(){
    int A[] = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    vector<int> nums(&A[0], &A[15]);
    Solution s;
    vector<vector<int> > ret = s.threeSum(nums);
    cout << ret.size() << endl;
    for (int i = 0; i < ret[0].size(); i++){
        cout << ret[0][i] << " ";
    }
    cout << endl;
}

