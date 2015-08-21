#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    bool VerifySquenceOfBST(vector<int> sequence){
        if (sequence.size() == 0)
            return false;
        if (sequence.size() == 1)
            return true;
        
        int root = sequence[sequence.size()-1];
        int i = 0;
        for (; i< sequence.size()-1; i++){
            if (sequence[i] > root)
                break;
        }

        int j = i;
        for (; j < sequence.size()-1; j++){
            if (sequence[j] < root)
                return false;
        }

        vector<int> left (sequence.begin(), sequence.begin()+i);
        vector<int> right (sequence.begin()+i, sequence.end()-1);

        bool flagLeft = true;
        bool flagRight = true;

        if (i > 0)
            flagLeft = VerifySquenceOfBST(left);

        if (i < sequence.size()-1)
            flagRight = VerifySquenceOfBST(right);

        return flagLeft && flagRight;
    }
};

int main(){

    int A[] = {1, 5, 3, 4};
    vector<int> nums(&A[0], &A[4]);

    Solution s;
    cout << s.VerifySquenceOfBST(nums) << endl;
}

