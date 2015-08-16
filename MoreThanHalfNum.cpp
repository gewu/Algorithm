#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int MoreThanHalfNum_Solution(vector<int> numbers){
        if (numbers.size() == 1)
            return numbers[0];
        int sum = 1;
        int value = numbers[0];
        
        for (int i = 1; i < numbers.size(); i++){
            if (numbers[i] == value){
                sum++;
            }else{
                sum--;
                if (sum == 0){
                    value = numbers[i];
                    sum = 1;
                }
            }
        }    

        sum = 0;
        for (int i = 0; i < numbers.size();i++){
            if (numbers[i] == value){
                sum++;
            }
        }
        if (sum > numbers.size()/2)
            return value;
        return 0;
    }
};

int main(){
    int A[] = {1,2,3,2,2,2,5,4,2};
    vector<int> nums(&A[0], &A[9]);
    Solution s;
    cout << s.MoreThanHalfNum_Solution(nums) << endl;
}
