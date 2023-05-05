#include <stdio.h>

int main(){
    int num, i , j;
    scanf("%d", &num);

    for(i = 2; i <= num; i++){
        for(j = 2; j < i; j++){
            if(i % j == 0){
                break;
            }
        }
        if(j == i){
            printf("%d ", i);
        }
    }
}