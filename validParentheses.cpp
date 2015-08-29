#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    bool isValid(string s){
        vector<char> stc;
        stc.push_back(s[0]);

        for (int j = 1; j < s.size(); j++){
            if (s[j] == '(' || s[j] == '[' || s[j] == '{'){
                stc.push_back(s[j]);
                continue;
            }

            if (stc.back() == '(' && s[j] != ')')
                return false;
            if (stc.back() == '[' && s[j] != ']')
                return false;
            if (stc.back() == '{' && s[j] != '}')
                return false;

            stc.pop_back();
        }
        return stc.size() == 0;
    }
};

int main(){
    string test = "{}][}}{[))){}{}){(}]))})[({";
    Solution s;
    cout << s.isValid(test) << endl;

}
