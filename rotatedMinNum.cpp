#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int minNumberInRotateArray(vector<int>& rotateArray){
        if (rotateArray.size() == 0){
            return -1;
        }
        if (rotateArray.size() == 1)
            return rotateArray[0];

        int start = 0;
        int end = rotateArray.size()-1;


        while (start < end){
            if (rotateArray[start] < rotateArray[end])
                return rotateArray[start];

            int mid = (start+end)/2;

            if (rotateArray[mid] == rotateArray[start] && rotateArray[mid] == rotateArray[end]){
                int min = rotateArray[start];
                for (int i = start; i <= end; i++){
                    if (rotateArray[i] < min)
                        min = rotateArray[i];
                }
                return min;
            }

            if (rotateArray[mid] >= rotateArray[start]){
                start = mid+1;
            }

            if (rotateArray[mid] <= rotateArray[end]){
                end = mid-1;
            }
        }

        return rotateArray[start];
    }
};

int main(){
    int A[] = {3,4,5,1,2};
    vector<int> nums(&A[0], &A[5]);
    Solution s;
    cout << s.minNumberInRotateArray(nums) << endl;
}

