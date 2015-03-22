#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};
class Solution{
public:
    TreeNode *sortedArrayToBST(vector<int> &num, int low, int high){
            if (low > high)
                return NULL;
            if (high - low == 0){
                TreeNode *tree = new TreeNode(num[low]);
                return tree;
            }
            int middle = (low+high)/2;
            TreeNode *tree = new TreeNode(num[middle]);
            tree->left = sortedArrayToBST(num, low, middle-1);
            tree->right = sortedArrayToBST(num, middle+1, high);
            return tree;
        }
};

int main(){
    vector<int> num;
    num.push_back(1);
    num.push_back(3);
    Solution solution;
    TreeNode *head = solution.sortedArrayToBST(num, 0, 1);
    cout << head->val << endl;
}

