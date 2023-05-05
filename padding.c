#include <stdio.h>

struct student { //구조체 선언
    char lastName[13];
    int studentId;
    short grade;
};

int main(){
    struct student pst; // student형 변수 선언
    printf("----- 오재식  2022040014 -----\n");
    printf("size of student = %ld\n", sizeof(struct student)); //구조채 student의 메모리 크기 출력
    printf("size of int = %ld\n", sizeof(int)); //int의 메모리 크기 출력
    printf("size of short = %ld\n", sizeof(short)); // short의 메모리 크기 출력

    return 0;
}