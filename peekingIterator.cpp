#include <iostream>
#include <vector>
using namespace std;

class Iterator{
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    int next();
    bool hasNext();
};

class PeekingIterator : public Iterator{
    Iterator* iter;
    int nextValue = 0;
    bool end = false;
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums){
        iter = new Iterator(nums);
        if (iter->hasNext()){
            nextValue = iter->next();
        }else {
            end = true;
        }
    }

    int peek(){
        if (end == false){
            return nextValue;
        }else {
            return 0;
        }
    }

    int next() {
        int current = nextValue;
        if (iter->hasNext()){
            nextValue = iter->next();
        }else {
            end = true;
        }
        return current;
    }

    bool hasNext() {
        if (end == true)
            return false;
        else 
            return true;
    }
};

int main(){

}
