#include <iostream>
using namespace std;

class Solution{
public:
    string addBinary(string a, string b){
        int l = a.length() > b.length() ? a.length()+1 : b.length()+1;
        string ret(l, '0');

        string::iterator itera = a.end()-1;
        string::iterator iterb = b.end()-1;
        int temp = 0;
        string::iterator iter = ret.end()-1;
        while(itera >= a.begin() && iterb >= b.begin()){
            int result = (*iter-'0' + *itera-'0' + *iterb-'0'+temp);
            if (result > 1){
                temp = 1;
                *iter = result%2+'0';
            }else{ 
                *iter = result+'0';
                temp = 0;
            }
            itera--;
            iterb--;
            iter--;
        }

        while (itera >= a.begin()){
            int result = *iter-'0' + *itera-'0'+temp;
            if (result > 1){
                temp = 1;
                *iter = result % 2 + '0';
            }else{ 
                *iter = result + '0';
                temp = 0;
            }
            itera --;
            iter--;
        }

        while (iterb >= b.begin()){
            int result = *iter-'0' + *iterb-'0'+temp;
            if (result > 1){
                temp = 1;
                *iter = result % 2 + '0';
            }else{
                *iter = result + '0';
                temp = 0;
            }
            iterb --;
            iter--;
        }
        if (temp == 0){
            string new_ret(ret.begin()+1, ret.end());
            return new_ret;
        }

        *iter += temp;
        return ret;
    }
};

int main(){

    string x = "1010";
    string y = "1011";

    Solution s;
    cout << s.addBinary(x, y) << endl;
    
}
