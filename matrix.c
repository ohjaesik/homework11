#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_martix(int** matrix, int row, int column){
    printf("matrix \n");
    for(int i = 0; i < row ; i++){ //1행부터 row행 까지 출력
        for(int j = 0; j < column; j++){ //1열부터 column열까지 출력
            printf("%d ", matrix[i][j] );
        }
        printf("\n");
    }
    printf("\n");
}
void free_matrix(int ** matrix, int row){

        for(int i=0; i<row; i++) 
            free(matrix[i]); //할당된 메모리 해제
        free(matrix); //할당된 메모리 해제
}

void addition_matrix(int **A, int **B, int A_n, int A_m, int B_n, int B_m){
    if(A_n != B_n || A_m != B_m){
        printf("A and B cannot be added \n"); //더할 수 없는 행렬인 경우 출력
        
    }
    else{
        int ** added_matrix = (int **)malloc(sizeof(int *) * A_n); //A+B의 값을 저장하기 위한 새로운 배열을 만듬
        
        for (int i =0; i < A_n; i++){
            added_matrix[i] = (int *)malloc(sizeof(int) * A_m); //A+B의 값을 저장하기 위한 새로운 배열을 만듬
            for(int j =0; j< A_m; j++){
                added_matrix[i][j] = A[i][j] + B[i][j]; //A의 i행 j열과 B의 i행 j열을 더하고 그 값을 added_matrix에 할당.
            }
        }
        print_martix(added_matrix, A_n, A_m);
        free_matrix(added_matrix, A_n);
    }
}

void subtraction_matrix(int **A, int **B, int A_n, int A_m, int B_n, int B_m){
    if(A_n != B_n || A_m != B_m){
        printf("A and B cannot be subtracted \n"); //뺄 수 없는 행렬인 경우 출력
        
    }
    else{
        int ** subtracted_matrix = (int **)malloc(sizeof(int *) * A_n); //A-B의 값을 저장하기 위한 새로운 배열을 만듬.
        
        for (int i =0; i < A_n; i++){
            subtracted_matrix[i] = (int *)malloc(sizeof(int) * A_m); //A-B의 값을 저장하기 위한 새로운 배열을 만듬.
            for(int j =0; j< A_m; j++){
                subtracted_matrix[i][j] = A[i][j] - B[i][j]; //A-B의 행렬 값을 subtracted_matrix에 저장.
            }
        }
        print_martix(subtracted_matrix, A_n, A_m);
        free_matrix(subtracted_matrix, A_n);
    }
}

void transpose_matrix(int **matrix,int row,int column){
    int ** transpose_matrix = (int**)malloc(sizeof(int*) * column); //전치 행렬을 만들기 위한 배열을 만듬
    for(int i =0; i < column; i++){
        transpose_matrix[i] = (int*)malloc(sizeof(int) * row); //전치행렬을 만들기 위한 배열을 만듬
    }
    for(int i = 0;i < row; i++){
        for(int j=0; j < column; j++){
            transpose_matrix[j][i] = matrix[i][j]; //matrix의 i행 j열을 transpose_matrix의 j행 i열에 할당
        }
    }
    print_martix(transpose_matrix, column, row);
    free_matrix(transpose_matrix, column);
}

void multiply_matrix(int **A, int **B, int A_n, int A_m, int B_n, int B_m){
    if(A_m != B_n){
        printf("A cannot be multiplied by B \n"); //행렬의 곱이 불가한 경우 출력
        
    }
    int **multiply_matrix = (int **)malloc(sizeof(int*) * A_n); //행렬의 곱의 결과를 저장할 배열 생성
    for(int i =0; i < A_n; i++){
        multiply_matrix[i] = (int *)malloc(sizeof(int) * B_m); //행렬의 곱의 결과를 저장할 배열 생성
        for(int j=0; j< B_m; j++){
            multiply_matrix[i][j] = 0; //행렬의 곱을 저장할 배열을 초기화해줌.
            for(int k=0; k < B_n; k++){
                multiply_matrix[i][j] += A[i][k] * B[k][j]; // 행렬의 곱의 결과를 저장함.
            }
            
        }
    }
    print_martix(multiply_matrix,A_n, B_m);
    free_matrix(multiply_matrix, A_n);
}

int main(){
    int A_n , A_m, B_n, B_m;
    printf("----- ohjaesik 2022040014 ----- \n");
    printf("input A matrix size : ");
    scanf("%d %d", &A_n, &A_m);
    printf("input B matrix size : ");
    scanf("%d %d", &B_n, &B_m);

    int ** A_martix = (int **)malloc(sizeof(int *) * A_n); //행렬 A의 행
    int ** B_martix = (int **)malloc(sizeof(int *) * B_n); //행렬 B의 행
    
    for(int i =0; i <A_n; i++){
        A_martix[i] = (int *)malloc(sizeof(int)* A_m); //행렬 A의 열
    }
    for(int i=0; i< B_n; i++){

        B_martix[i] = (int *)malloc(sizeof(int)* B_m); //행렬 B의 열
    }
    for(int i=0; i<A_n; i++){
        for(int j=0; j<A_m; j++){
            A_martix[i][j] = rand() % 10; //행렬 A의 임의의 값 할당
        }
    }
    for(int i=0; i<B_n; i++){
        for(int j=0; j<B_m; j++){
            B_martix[i][j] = rand() % 10; //행렬 B의 임의의 값 할당
        }
    }
    printf("--- A_matrix --- \n");
    print_martix(A_martix, A_n, A_m);
    
    printf("--- B_matrix --- \n");
    print_martix(B_martix,B_n, B_m);
    
    printf("--- A+B matrix --- \n");
    addition_matrix(A_martix,B_martix,A_n,A_m,B_n,B_m);
    
    printf("--- A-B matrix --- \n");
    subtraction_matrix(A_martix, B_martix, A_n, A_m, B_n, B_m);

    printf("--- Transpose matrix --- \n");
    transpose_matrix(A_martix,A_n,A_m);

    printf("--- A*B matrix --- \n");
    multiply_matrix(A_martix,B_martix,A_n,A_m,B_n,B_m);
    return 0;
}