#include <stdio.h>
#include <stdlib.h>

void replaceSpace(char *str, int length){
    int len = length;
    for (int i = 0; i < length; i++){
        if (str[i] == ' '){
            len += 2;
        }
    }
        
    for (int i = length-1, j = len-1; j >= 0; j--, i--){
        if (str[i] == ' '){
            str[j] = '0';
            str[--j] = '2';
            str[--j] = '%';
        }else {
            str[j] = str[i];
        }
    }
}

int main(){
    char str[100] = "We are happy";
    replaceSpace(str, 13);
    printf("%s\n", str);
}
