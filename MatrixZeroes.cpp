#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix){
        set<int> row;
        set<int> col;

        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[i].size(); j++){
                if (matrix[i][j] == 0){
                    row.insert(i);
                    col.insert(j);
                }        
            }
        }

        for (set<int>::iterator it = row.begin(); it != row.end(); it++){
            for (int j = 0; j < matrix[*it].size(); j++){
                matrix[*it][j] = 0;
            }
        }

        for (set<int>::iterator it = col.begin(); it != col.end(); it++){
            for (int i = 0; i < matrix.size(); i++){
                matrix[i][*it] = 0;
            }
        }
    }
};

int main(){
    int A[] = {2,0,0};
    int B[] = {1,1,1};
    vector<int> numA(&A[0], &A[3]);
    vector<int> numB(&B[0], &B[3]);
    vector<vector<int> >nums;
    nums.push_back(numA);
    nums.push_back(numB);

    Solution s;
    s.setZeroes(nums);

    for (int i = 0; i < nums.size(); i++){
        for (int j = 0; j < nums[i].size(); j++){
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
}

