#include <stdio.h>
#include <stdlib.h>
struct student1 { //구조체 선언
    char lastName;
    int studentId;
    char grade;
};

typedef struct { //구조체 선언
    char lastName;
    int studentId;
    char grade;
}student2;

int main(){
    struct student1  st1 = {'A', 100, 'A'}; //student1형 변수에 선언후 값 할당
    printf("----- 오재식  2022040014 -----\n");
    printf("st1.lastName = %c\n", st1.lastName); // st1.lastName출력
    printf("st1.studentId = %d\n", st1.studentId); // st1.studentId출력
    printf("st1.grade = %c\n", st1.grade); // st1.grade출력

    student2 *st2 = malloc(sizeof(student2)); //student2형 포인터 변수 선언후 메모리 할당
    st2->lastName = 'B'; //화살표 함수를 사용하여 값 할당
    st2->studentId = 200;
    st2->grade = 'B';
    printf("st2.lastName = %c\n", st2->lastName); //포인터 st2가 가리키는 주소값의 lastName 출력
    printf("st2.studentId = %d\n", st2->studentId); //포인터 st2가 가리키는 주소값의 studentId 출력
    printf("st2.grade = %c\n", st2->grade); //포인터 st2가 가리키는 주소값의 grade 출력

    student2 *st3; //student2형 포인터 변수 선언
    st3 = st2; // st3에 st2값 할당
    printf("\nst3.lastName = %c\n", st3->lastName); //포인터 st3가 가리키는 주소값의 lastName 출력
    printf("st3.studentId = %d\n", st3->studentId); //포인터 st3가 가리키는 주소값의 studentId 출력
    printf("st3.grade = %c\n", st3->grade); //포인터 st3가 가리키는 주소값의 grade 출력
    if(st2 == st3) //st2와 st3가 동치이면 equal, 아니면 not equal 출력
        printf("equal\n");
    else
        printf("not equal\n");

    return 0;
}