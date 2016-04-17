#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<int> countBits(int num){
        vector<int> result(num+1);

        for(int i = 1; i <= num; i++){
            result[i] += result[i&(i-1)]+1;
        }
    return result;
    }
};

int main(){
    Solution s;
    vector<int> ret = s.countBits(5);
    for (int i = 0; i < ret.size(); i++){
        cout << ret[i] << " ";
    }
    cout << endl;
}
