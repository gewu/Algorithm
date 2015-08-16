#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int FindGreatestSumOfSubArray(vector<int> array){
        int sum = array[0];
        int max = array[0];
        for (int i = 1; i < array.size(); i++){
            sum += array[i];
            if (sum > max){
                max = sum;
            }
            if (sum < 0){
                sum = 0;
            }
        }
        return max;
    }
};

int main(){
    int A[] = {6,-3,-2,7,-15,1,2,2};
    vector<int> nums(&A[0], &A[8]);
    Solution s;
    cout << s.FindGreatestSumOfSubArray(nums) << endl;
}
