#include <iostream>
using namespace std;

class Solution{
public:
    int addDigits(int num){
        if (num/10 == 0)
            return num;
        int sum = 0;
        while (num/10 != 0){
            sum += num%10;
            num = num/10;
        }
        return addDigits(sum+num);
    }
};

int main(){
    Solution s;
    cout << s.addDigits(38) << endl;
}
