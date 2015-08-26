#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle){
        vector<int> preSum (triangle.back().size(), -2134);
        vector<int> tempSum (triangle.back().size(), -2134);
        preSum[0] = triangle[0][0];

        for (int i = 1; i < triangle.size();i++){
            for (int j = 0; j < triangle[i-1].size(); j++){
                for (int k = j; k <= j+1; k++){
                    if (tempSum[k] == -2134){
                        tempSum[k] = preSum[j]+triangle[i][k];
                    }else if (tempSum[k]!= -2134){
                        int temp = preSum[j]+triangle[i][k];
                        tempSum[k] = tempSum[k] < temp ? tempSum[k] : temp;
                    }
                }
                preSum[j] = -2134;
            }
            preSum.swap(tempSum);
        }
        if (triangle.size() == 1)
            preSum = triangle.back();

        int min = preSum[0];
        for (int j = 1; j < preSum.size(); j++){
            if (min > preSum[j]){
                min = preSum[j];
            }
        }
        return min;
    }
};


int main(){
    int A[] = {2};
    int B[] = {3,4};
    int C[] = {6,5,7};
    vector<int> ANums(&A[0], &A[1]);
    vector<int> BNums(&B[0], &B[2]);
    vector<int> CNums(&C[0], &C[3]);
    vector<vector<int> > nums;
    nums.push_back(ANums);
    nums.push_back(BNums);
    nums.push_back(CNums);

    Solution s;
    cout << s.minimumTotal(nums) << endl;

}
