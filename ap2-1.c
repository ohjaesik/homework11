#include <stdio.h>
#define MAX_SIZE 100

float sum1(float list[], int); // sum1함수 호출
float sum2(float *list, int); // sum2함수 호출
float sum3(int n, float *list); // sum3함수 호출

float input[MAX_SIZE], answer; // 변수 선언
int i; // 변수 선언
int main(void){
    for(i=0; i< MAX_SIZE; i++)
        input[i] = i; // input[i] 배열에 i값 할당
    printf("----- 오재식  2022040014 -----");
    printf("------------------------\n"); 
    printf("sum1(input, MAX_SIZE) \n");
    printf("------------------------\n");
    printf("input \t = %p\n", input); // input의 주소값 출력

    answer = sum1(input, MAX_SIZE); // answer에 sum1 return 값 할당
    printf("The sum is : %f\n\n", answer); // answer 값 출력

    printf("------------------------\n");
    printf("sum2(input, MAX_SIZE) \n");
    printf("------------------------\n");
    printf("input \t = %p\n", input); // input의 주소값 출력

    answer = sum2(input, MAX_SIZE); // answer에 sum2 return 값 할당
    printf("The sum is : %f\n\n", answer); // answer 값 출력


    printf("------------------------\n");
    printf("sum3(MAX_SIZE, input) \n");
    printf("------------------------\n");
    printf("input \t = %p\n", input); // input의 주소값 출력

    answer = sum3(MAX_SIZE, input); // answer에 sum3 return 값 할당
    printf("The sum is : %f\n\n", answer); // answer 값 출력
}

float sum1(float list[0], int n){
    printf("list \t= %p\n", list); //list의 주소값 출력
    printf("&list \t = %p\n", &list); // list의 주소값 출력

    int i;
    float tempsum = 0;
    for(i=0; i<n; i++)
        tempsum += list[i]; //list의 모든 값을 합함.

    return tempsum; // tempsum값 리턴
}

float sum2(float *list, int n){
    printf("list \t= %p\n", list); //list의 주소값 출력
    printf("&list \t = %p\n", &list); // list의 주소값 출력

    int i;
    float tempsum = 0;
    for(i=0; i<n; i++)
        tempsum += list[i]; //list의 모든 값을 합함.

    return tempsum; // tempsum값 리턴
}

float sum3(int n, float *list){
    printf("list \t= %p\n", list); //list의 주소값 출력
    printf("&list \t = %p\n", &list); // list의 주소값 출력

    int i;
    float tempsum = 0;
    for(i=0; i<n; i++)
        tempsum += list[i]; //list의 모든 값을 합함.

    return tempsum; // tempsum값 리턴
}