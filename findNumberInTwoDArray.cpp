#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    bool Find(vector<vector<int> > array, int target){
        int j = array[0].size()-1;
        int i = 0;

        while (j >= 0 && i < array.size()){
            if (array[i][j] < target)
                i++;
            else if (array[i][j] > target)
                j--;
            else 
                return true;              
        }
        return false;
    }
};

int main(){

}
