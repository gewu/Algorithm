#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    int rectCover(int number){
        vector<int> ret(number+1, 0);
        ret[0] = 1;
        ret[1] = 1;
        ret[2] = 2;
        for (int i = 3; i <= number; i++){
            ret[i] = ret[i-1] + ret[i-2];
        }
        return ret[number];
    }
};

int main(){
   Solution s;
   cout << s.rectCover(5) << endl;
}
