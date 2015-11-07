#include <iostream>
#include <vector>
#include <map>
#include <multiset>

using namespace std;

class Solution {
public:
    bool containsNearbyAlostDuplicate(vector<int>& nums, int k, int t){
        for (int i = 0; i < nums.size(); i++){
            cout << nums.size()<< endl;
            for (int j = i+1; j <= i+k && j < nums.size(); j++){
                if (abs(nums[i]-nums[j]) <= t)
                    return 1;
            }
        }
        return 0;
    }

    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t){
        multiset<long long> bst;
        for (int i = 0; i < nums.size(); i++){
            if (bst.size() == k+1)
                bst.earse(bst.find(nums[i-k-1]));
            auto lb = bst.lower_bound(nums[i]-t);
            if (lb != bst.end() && *lb-nums[i] <= t)
                return true;
            bst.insert(nums[i]);
        }
        return false;
    
    }              
    
};

int main(){
    int A[] = {-1, -1};
    vector<int> nums(&A[0], &A[2]);
    Solution s;
    cout << s.containsNearbyAlostDuplicate(nums, 1, 0) << endl;

}
