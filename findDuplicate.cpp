#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int findDuplicate(vector<int>& nums){
        int l = 1;
        int r = nums.size()-1;
        int mid = 0;
        int c = 0;
        while (l <= r){  
            mid = (l+r) >> 1;
            c = cnt(nums, mid);

            if (c <= mid)
                l = mid+1;
            else 
                r = mid-1;
        }
        return l;
    }

    int cnt(vector<int>& nums, int n){
        int ret = 0;
        for (auto v : nums){
            if (v <= n)
                ret++;
        }
        return ret;
    }
    
    
};

int main(){
    vector<int> nums{1,1,2};
    Solution s;
    cout << s.findDuplicate(nums) << endl;
}
