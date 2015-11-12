#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int maxArea(vector<int>& height){
        int l = 0;
        int r = height.size()-1;
        int max = 0;
        int tmp = 0;
        while (l < r){
            tmp = r-l;
            tmp *= height[l] > height[r] ? height[r--] : height[l++];    
            if (tmp > max)
                max = tmp;
        }

        return max;
    }
};

int main(){
    vector<int> nums{2,1,4,5,6,9};
    Solution s;
    cout << s.maxArea(nums) << endl;
}
