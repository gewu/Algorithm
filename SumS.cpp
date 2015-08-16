#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum){
        int i = 0;
        int j = array.size()-1;
        vector<int> ret;

        while (i <= j){
            if (array[i]+array[j] > sum){
                j--;
            }else if (array[i]+array[j] < sum){
                i++;
            }else {
                if (ret.size() == 0){
                    ret.push_back(array[i]);
                    ret.push_back(array[j]);
                }else if (ret[0]*ret[1] > array[i]*array[j]){
                    ret[0] = array[i];
                    ret[1] = array[j];
                }
                i++;
                j--;
            }
            
        }
        return ret;
    }
};

int main(){
    int A[] = {1,2,3,7,8,9};
    vector<int> nums(&A[0], &A[6]);
    Solution s;
    vector<int> myret = s.FindNumbersWithSum(nums, 10);
    for (int i = 0; i < myret.size();i++){
        cout << myret[i] << " ";
    }
    cout << endl;
    
}
