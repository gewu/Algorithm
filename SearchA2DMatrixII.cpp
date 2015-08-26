#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target){
        int i = 0;
        int j = matrix[0].size()-1;

        while (i < matrix.size() && j >= 0){
            if (matrix[i][j] == target)
                return true;
            if (matrix[i][j] > target)
                j--;
            if (matrix[i][j] < target)
                i++;
        }
        return false;
    }
};

int main(){

    int A[] = {1,4,7,11,15};
    int B[] = {2,5,8,12,19};
    int C[] = {3,6,9,16,22};
    int D[] = {10,13,14,17,24};
    int E[] = {18,21,23,26,30};

    vector<int> numA(&A[0], &A[5]);
    vector<int> numB(&B[0], &B[5]);
    vector<int> numC(&C[0], &C[5]);
    vector<int> numD(&D[0], &D[5]);
    vector<int> numE(&E[0], &E[5]);
    
    vector<vector<int> > nums;
    nums.push_back(numA);
    nums.push_back(numB);
    nums.push_back(numC);
    nums.push_back(numD);
    nums.push_back(numE);
    Solution s;
    cout << s.searchMatrix(nums, 20) << endl;

}
