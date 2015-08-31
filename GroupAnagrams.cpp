#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution{
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs){
        vector<vector<string> > result;
        sort(strs.begin(), strs.end());

        map<string, vector<string> > codeToStrs;
        for (int i = 0; i < strs.size(); i++){
            codeToStrs[getCode(strs[i])].push_back(strs[i]);
        }

        for (map<string, vector<string> >::iterator it = codeToStrs.begin(); it != codeToStrs.end(); it++){
            result.push_back(it->second);
        }

        return result;

    }

    string getCode(string s){
        sort(s.begin(), s.end());
        return s;
    }


};

int main(){

    vector<string> strs;
    strs.push_back("eat");
    strs.push_back("tea");
    strs.push_back("tan");
    strs.push_back("ate");
    strs.push_back("nat");
    strs.push_back("bat");
    Solution s;
    //vector<vector<string> > ret = s.groupAnagrams(strs);
    /*
    for (int i = 0; i < ret.size(); i++){
        for (int j = 0; j < ret[i].size(); j++){
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }*/
}

