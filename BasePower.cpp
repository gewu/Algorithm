#include <iostream>
using namespace std;

class Solution{
public:
    double Power(double base, int exponent){
        if (exponent == 1)
            return base;

        if (exponent % 2 == 0)
           return Power(base, exponent/2)*Power(base, exponent/2);
        return Power(base, exponent/2)*Power(base, exponent/2)*base;
    }
};

int main(){
    Solution s;
    cout << s.Power(2, 9) << endl;
}
