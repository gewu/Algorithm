#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target){
        for (int i = 0 ; i < matrix.size(); i++){
            if (matrix[i][0] <= target && matrix[i].back() >= target){
                return binarySearch(matrix[i], target);
            }
        }
        return false;
    }

    bool binarySearch(vector<int>& row, int target){
        int i = 0; 
        int j = row.size()-1;

        while (i < j){
            int mid = (i+j)/2;
            if (row[mid] == target)
                return true;
            else if (row[mid] > target){
                j = mid-1;
            }else if (row[mid] < target){
                i = mid+1;
            }
        }
        return (row[i] == target);
    }
};

int main(){
    int A[] = {1,3,5,6};
    int B[] = {10,11,16,20};
    int C[] = {23,30,34,50};

    vector<int> num1(&A[0], &A[4]);
    vector<int> num2(&B[0], &B[4]);
    vector<int> num3(&C[0], &C[4]);

    vector<vector<int> > nums;
    nums.push_back(num1);
    nums.push_back(num2);
    nums.push_back(num3);

    Solution s;
    cout << s.searchMatrix(nums, 50) << endl;
    
}
