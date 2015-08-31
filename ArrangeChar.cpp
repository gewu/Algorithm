#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution{
public:
    vector<string> Permutation(string str){
        sort(str.begin(), str.end());
        vector<string> ret;
        if (str.size() == 0)
            return ret;
        string tmp;
        set<string> sret;
        help(str, 0, sret, tmp);
        vector<string> result(sret.begin(), sret.end());
        return result;
    }

    void help(string str, int index, set<string>& ret, string& tmp){
        if (tmp.size() == str.size()){
            ret.insert(tmp);
        }
        for (int j = index; j < str.size(); j++){
            swap(str[index], str[j]);
            tmp.push_back(str[index]);
            help(str, index+1, ret, tmp);
            tmp.pop_back();
            swap(str[index], str[j]);
        }
    }
};

int main(){
    string str("aa");
    Solution s;
    vector<string> ret = s.Permutation(str);
    for (int i = 0; i < ret.size(); i++){
        cout << ret[i] << endl;
    }
}
