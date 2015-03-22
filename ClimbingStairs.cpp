#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int climbStairs(int n){
        vector<int> num(n+2, 0);
        num[1] = 1;
        num[2] = 2;
        if (n <= 2)
            return num[n];
        for (int i = 3; i <= n; i++)
            num[i] = num[i-1] + num[i-2];
        return num[n];
    }
};

int main(){
    Solution solution;
    int val = solution.climbStairs(5);
    cout << val << endl;
}
