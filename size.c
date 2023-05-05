#include <stdio.h>
#include <stdlib.h>

int main(){
    int **x;
    printf("----- 오재식  2022040014 -----\n");
    printf("sizeof(x) = %lu\n", sizeof(x)); //변수 x에 할당된 메모리 사이즈 출력
    printf("sizeof(*x) = %lu\n", sizeof(*x)); // *x에 할당된 메모리 사이즈 출력
    printf("sizeof(**x) = %lu \n", sizeof(**x)); // **x에 할당된 메모리 사이즈 출력

    return 0;
}