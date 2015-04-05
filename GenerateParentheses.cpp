#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<string> generateParenthesis(int n){
        vector<string> items;
        generate(items, "", n, n);
        return items;
    }

    void generate(vector<string>& items, string item, int l, int r){
        if (l < r)
            return ;
        if (l == 0 && r == 0)
            items.push_back(item);
        if (l > 0)
            generate(items, item+")", l-1, r);
        if (r > 0)
            generate(items, item+"(", l, r-1);
    }
};

int main(){
    Solution solution;
    vector<string> items = solution.generateParenthesis(3);
    cout << items.size() << endl;
    cout << items[1] << endl;
}
