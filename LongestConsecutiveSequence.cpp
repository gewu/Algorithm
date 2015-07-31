#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution{
public:
    int longestConsecutive(vector<int>& nums){
        set<int> flag;

        for (int i = 0; i<nums.size();i++){
            flag.insert(nums[i]);
        }
        
        int maxV = -1;
        for (int i = 0; i<nums.size(); i++){
            int left = nums[i] - 1;
            int right = nums[i] + 1;
            int count = 1;
            while (flag.find(left) != flag.end()){
                count ++;
                flag.erase(left);
                left --;
            }

            while (flag.find(right) != flag.end()){
                count ++;
                flag.erase(right);
                right++;
            }

            maxV = maxV > count ? maxV:count;
        }
        return maxV;
    }
};

int main(){
    int A[] = {100, 4, 200, 1, 3, 2};
    vector<int> nums(&A[0], &A[6]);
    Solution s;
    cout << s.longestConsecutive(nums) << endl;
}



