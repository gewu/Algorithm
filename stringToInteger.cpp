#include <iostream>
using namespace std;

class Solution{
    public:
        int myAtoi(string str){
            if (str.length() <= 0)
                return 0;
            int i = 0;
            while (str[i] == ' '&& i < str.length()){
                i++;  
            }

            int size = 0; 
            int flag = 1;
            int sum = 0;
            int flagNum = 0;
            while (i < str.length()){
                if (str[i] >= '0' && str[i] <= '9'){
                    sum *= 10;
                    size ++;
                    sum += str[i]-'0';
                    if (size > 10)
                        return flag > 0 ? 2147483647 : -2147483648;
                    i++;
                    continue;
                }
                if (str[i] == '+'){
                    i++;
                    flagNum ++;
                    if (flagNum >= 2)
                        return 0;
                    continue;
                }else if (str[i] == '-'){
                    i++;
                    flag = -1;
                    flagNum++;
                    if (flagNum >= 2)
                        return 0;
                    continue;
                }else {
                    break;
                }
            }
            if (sum < 0)
                return flag > 0 ? 2147483647 : -2147483648;
            return sum*flag;
        }
};

int main(){
    string str = "  -1123u1212";
    Solution s;
    cout << s.myAtoi(str) << endl;
}
