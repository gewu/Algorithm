#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<vector<string> > partition(string s){
        vector<vector<string> >res;
        if (s.size() == 0)
            return res;

        vector<string> tmp;
        help(s, tmp, res);
        return res;
    }

    void help(string s, vector<string>& tmp, vector<vector<string> >&res){
        if (s.size() == 0){
            res.push_back(tmp);
            return ;
        }

        for (int i = 1; i <= s.size(); i++){
            string tmpS = s.substr(0, i);
            if (isPalindrome(tmpS)){
                tmp.push_back(tmpS);
                help(s.substr(i, s.size()-i), tmp, res);
                tmp.pop_back();
            }
        }
    }

    bool isPalindrome(string s){
        if (s.size() == 1)
            return true;
        int i = 0;
        int j = s.length()-1;
        while (i < j){
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
};

int main(){
    string str = "aba";
    Solution s;
    vector<vector<string> >res = s.partition(str);
    cout << str.size() << endl;
    for (int i = 0; i < res.size(); i++){
        for (int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

}
