#include <stdio.h>
#include <stdlib.h>

int main(){
    int list[5]; // 5개짜리 배열을 만듬
    int *plist[5]; // 5개짜리 포인터 배열을 만듬

    list[0] = 10; // list[0]에 10할당
    list[1] = 11; // list[1]에 11할당

    plist[0] = (int*)malloc(sizeof(int)); //plist[0]에 int 메모리 주소 할당
    printf("----- 오재식  2022040014 -----\n"); 
    printf("list[0] \t= %d\n", list[0] ); //list[0]에 할당된 값 출력
    printf("list \t\t= %p\n", list); // list의 주소값 출력
    printf("&list[0] \t=%p\n", &list[0]); // list[0]번째 주소값 출력
    printf("list+0 \t= %p\n", list+0); // list의 주소값 출력
    printf("list+1 \t= %p\n", list+1); // list 1번째 주소값 출력
    printf("list+2 \t= %p\n", list+2); // list 2번째 주소값 출력
    printf("list+3 \t= %p\n", list+3); // list 3번째 주소값 출력 
    printf("list+4 \t= %p\n", list+4); // list 4번째 주소값 출력
    printf("&list[4] \t= %p\n", &list[4]); // list[4]번째 주소값 출력

    free(plist[0]); // plist[0]번째에 할당된 메모리값 해제
    return 0;
}