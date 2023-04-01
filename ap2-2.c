#include <stdio.h>

void print_one(int *ptr, int rows); //print_one 함수 호출

int main(){
    int one[] = {0,1,2,3,4}; // one배열에 값 할당
    printf("----- 오재식  2022040014 -----");
    printf("one = %p\n", one); // one의 주소값 출력
    printf("&one = %p\n", &one); // one의 주소값 출력
    printf("&one[0] = %p\n", &one[0]); // one[0]번째 주소값 출력
    printf("\n");

    printf("-----------------------------\n");
    printf("  printf_one(&one[0], 5) \n");
    printf("-----------------------------\n");
    print_one(&one[0], 5); //print_one함수 실행

    printf("-----------------------------\n");
    printf("  print_one(one, 5) \n");
    printf("-----------------------------\n");
    print_one(one, 5); // print_one함수 실행

    return 0;
}

void print_one(int *ptr, int rows){
    int i;
    printf("Address \t Contents \n");
    for(i = 0; i < rows; i++)
        printf("%p \t %5d\n", ptr +i, *(ptr+i)); //포인터 ptr로 받아온 값들의 주소값을 rows까지 출력
    printf("\n");
}