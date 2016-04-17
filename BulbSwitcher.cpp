#include <iostream>
#include <math.h>
using namespace std;

class Solution{
public:
    int bulbSwitch(int n){
        return sqrt(n);       
    }
};

int main(){
    Solution s;
    cout << s.bulbSwitch(5) << endl;
}
