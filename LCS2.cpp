#include <iostream>
#include <vector>
using namespace std;

int ConLCS(string& text, string& query){
    vector<vector<int> > array(text.length(), vector<int>(query.length(), 0));
    int max = 0;

    for (int i = 0; i < text.length(); i++){
        for (int j = 0; j < query.length();j++){
            if (text[i] == query[j]){
                array[i][j] = array[i-1][j-1]+1;
                if (array[i][j] > max){
                    max = array[i][j];
                }
            }
        }
    }
    return max;
}

int main(){
    string text = "BEDCF";
    string query = "EHCF";
    cout << ConLCS(text, query) << endl;
}
