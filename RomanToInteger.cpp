#include <iostream>
#include <map>
using namespace std;

class Solution{
public:
    int romanToInt(string s){
        int ret = 0;
        map<char, int> roman;
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;

        for (int i = 0; i < s.length(); i++){
            if (roman[s[i]] >= roman[s[i+1]])
                result += roman[s[i]];
            else 
                result -= roman[s[i]];
        }
        return result
    }
};
