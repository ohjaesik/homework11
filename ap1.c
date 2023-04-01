#include <stdio.h>
#include <stdlib.h>
void main() {
    int list[5]; //5개짜리 배열을 만듬
    int *plist[5] = {NULL,}; //5개의 포인터 배열을 만듬
    plist[0] = (int *)malloc(sizeof(int)); // plist 0번째 배열에 int 메모리 할당
    list[0] = 1; // list 0번째 자리에 1할당
    list[1] = 100; // list 1번째 자리에 100할당
    *plist[0] = 200; // 포인터plist가 가르키는 곳에 200할당
    printf("----- 오재식  2022040014 -----");
    printf("list[0] = %d\n", list[0]); // list 0번째 값 출력
    printf("&list[0] = %p\n", &list[0]); // list 0번째 주소값 출력
    printf("list = %p\n", list); // list 주소값 출력
    printf("&list = %p\n ", &list); // list의 주소값 출력
    printf("----------------------------------------\n\n");
    printf("list[1] = %d\n", list[1]); // list 1번째 값 출력
    printf("&list[1] = %p\n", &list[1]); // list 1번째 주소값 출력
    printf("*(list+1) = %d\n", *(list + 1)); // list 1번째 값 출력
    printf("list+1 = %p\n", list+1); // list 1번째 주소값 출력

    printf("--------------------------------------\n\n");
    printf("*plist[0] = %d\n", *plist[0]); // *plist[0]의 할당된 값 출력
    printf("&plist[0] = %p\n", &plist[0]); // plist[0]의 주소값 출력
    printf("&plist = %p\n", &plist); // plist의 주소값 출력
    printf("plist = %p\n", plist); // plist 주소값 출력
    printf("plist[0] = %p\n", plist[0]); // plist[0]의 할당된 malloc의 주소값 출력
    printf("plist[1] = %p\n", plist[1]); // 포인터 plist[1]의 할당된 주소값 출력
    printf("plist[2] = %p\n", plist[2]); // 포인터 plist[2]의 할당된 주소값 출력
    printf("plist[3] = %p\n", plist[3]); // 포인터 plist[3]의 할당된 주소값 출력
    printf("plist[4] = %p\n", plist[4]); // 포인터 plist[4]의 할당된 주소값 출력

    free(plist[0]); // plist[0]의 할당된 메모리 해제
}



