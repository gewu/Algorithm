#include <iostream>
using namespace std;

int getLength(char* str, int n){
    if(NULL == str || n < 1)
        return 0;

    int max = 0;
    int i = 0;
    int j = 1;
                                        // get center num
    for (; i < n; i++){
        while (i-j >= 0 && i+j < n){   // odd
            if (str[i-j] == str[i+j]){
                j++;
            }else {
                break;
            }
        }
        --j;
        if (j*2+1 > max)
            max = j*2+1;
        
        j = 0;
        while (i-j >= 0 && i+j+1 < n){       //even
            if (str[i-j] == str[i+j+1]){
                j++;
            }else {
                break;
            }

        }
        if (j*2 > max)
            max = j*2;
    }
    return max;
}

int main(){

    char p[] = "1111";
    cout << getLength(p,4) << endl; 
}
