#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    void reOrderArray(vector<int>& array){
        if (array.size() <= 1)
            return ;
        int i = -1;
        int j = i+1;
        while (true){
            while (array[++i] % 2 != 0){
                if (i == array.size()-1)
                    break;
            }

            while (array[++j] % 2 == 0){
                if (j == array.size()-1)
                    break;
            }

            if (i >= j)
                break;
            swap(array[i], array[j]);

            if (i == array.size()-1 || j == array.size()-1)
                break;
        }
    }

};

int main(){

    int A[] = {2,4,6,1,3,5};
    vector<int> nums(&A[0], &A[6]);
    Solution s;
    s.reOrderArray(nums);
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
}
