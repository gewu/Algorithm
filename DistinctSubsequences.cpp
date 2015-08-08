#include <iostream>
using namespace std;

class Solution{
public:
    int numDistinct(string s, string t){
        int lens = s.length();
        int lent = t.length();
        if (lent == 0)
            return 0;
        else if (lens == 0)
            return 0;
        int dp[lens+1][lent+1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < lens; i++)
            dp[i][0] = 1;
        for(int i = 1; i <= lens; i++){
            for (int j = 1; j<=lent; j++){
                if (s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
                else 
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[lens][lent];
    }
};

int main(){
    string s = "rabbbit";
    string t = "rabbit";
    Solution sn;
    cout << sn.numDistinct(s, t) << endl;
}
