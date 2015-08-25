#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int getKnum(vector<int>& nums, int k){
        int end = nums.size() -1;
        int start = 0;
        int p = partition(nums, start, end);
        cout << "p " << p << endl;
        int q = nums.size()-k;
        while (p != q){
            if (p > q)
                p = partition(nums, start, p-1);
            else 
                p = partition(nums, p+1, end);
        }
        return nums[p];
    }

    int getNum(vector<int>& nums, int k){
        return findK(nums, nums.size()-k, 0, nums.size()-1);
    }

    vector<int> findLeastNumbers_solution(vector<int> input, int k){
        findK(input, k, 0, input.size()-1);
        vector<int> ret(&input[0], &input[k]);
        return ret;
    }

    int findK(vector<int>& nums, int k, int i, int j){
        if (i >= j)
            return nums[i];
        int m = partition(nums, i, j);
        if (m == k)
            return nums[m];
        else if (m < k){
            return findK(nums, k, m+1, j);
        }else {
            return findK(nums, k, i, m-1);
        }
    }

    void quickSort(vector<int>& nums, int start, int end){
        if (start > end)
            return ;
        int p = partition(nums, start, end);
        quickSort(nums, start, p-1);
        quickSort(nums, p+1, end);
    }

    int partition(vector<int>& nums, int start, int end){
        int key = nums[start];
        int i = start;
        int j = end+1;

        while (true){
            while (nums[++i] < key){
                if (i == end)
                    break;
            }

            while (nums[--j] > key){
                if (j == start)
                    break;
            }

            if (i >= j)
                break;
            swap(nums[i], nums[j]);
        }

        swap(nums[start], nums[j]);
        return j;
    }
};


int main(){
    int A[] = {2,1};
    vector<int> nums(&A[0], &A[2]);
    Solution s;
    //s.quickSort(nums, 0, 4);
    vector<int> test = s.findLeastNumbers_solution(nums, 2);
    for (int i = 0; i < test.size(); i++){
        cout << test[i] << " ";
    }

    //cout << s.getNum(nums, 1) << endl;

}
