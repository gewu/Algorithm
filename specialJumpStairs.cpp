#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int jumpFloor(int number){
        vector<int> ret(number+1, 0);
        ret[1] = 1;
        ret[2] = 2;
        for (int i = 3; i <= number; i++){
            ret[i] = ret[i-1] + ret[i-2];
        }
        return ret[number];
    }

    int specialJumpFloor(int number){
        vector<int> ret(number+1, 0);
        ret[1] = 1;
        ret[2] = 2;
        int sum = 3;
        for (int i = 3; i <= number; i++){
            ret[i] = sum+1;
            sum += ret[i];
        }
        return ret[number];
    }
};

int main(){
    Solution s;
    cout << s.jumpFloor(4) << endl;
    cout << s.specialJumpFloor(4) << endl;
}
