#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target){
        int start = 0;
        int end = nums.size()-1;
        int mid = 0;
        while (start < end){
            mid = (start+end)/2;
            if (nums[start] == target)
                return start;
            if (nums[end] == target)
                return end;
            if (nums[mid] == target)
                return mid;

            if (target >= nums[0]){
                if (nums[mid] > nums[0]){
                    if (nums[mid] >= target)
                        end = mid-1;
                    else 
                        start = mid+1;
                }else {
                    end = mid-1;
                }
            }else {
                if (nums[mid] < nums[0]){
                    if (nums[mid] >= target){
                        end = mid-1;
                    }else {
                        start = mid+1;
                    }
                }else {
                    start = mid+1;
                }
            }          
        }

        return nums[start] == target ? start : -1;
    }
};

int main(){
    int A[] = {1,3};
    vector<int> nums(&A[0], &A[2]);
    Solution s;
    cout << s.search(nums, 3) << endl;
}
