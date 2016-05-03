#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool cmp_by_value(const pair<int, int>lhs, const pair<int, int>rhs){
    return lhs.second < rhs.second;
}

class Solution{
public:
    vector<int> topKFrequent(vector<int>& nums, int k){
        map<int, int> counter;
        for (vector<int>::iterator iter = nums.begin();
             iter != nums.end(); iter++){
            if (counter.find(*iter) != counter.end()){
                counter[*iter] ++;
            }else {
                counter.insert(make_pair(*iter, 1));
            }
        }

        vector<pair<int, int> > resultAll(counter.begin(), counter.end());
        sort(resultAll.begin(), resultAll.end(), cmp_by_value);
        vector<int> ret;
        for (int i = 1; i <= k; i++){
            ret.push_back(resultAll[resultAll.size()-i].first);
        }
        return ret;
    }
};
