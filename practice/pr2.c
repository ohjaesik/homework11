#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, j;
    scanf("%d %d", &i, &j);
    int num = 1;
    int **matrix = (int **)malloc(sizeof(int*) * i);
    for(int row = 0; row<i ; row ++){
        matrix[row] = (int *)malloc(sizeof(int) *j);
        for(int col = 0; col<j; col++ ,num++){
            matrix[row][col] = num;
        }
    }
    for(int row = 0; row<i; row++){
        for(int col = 0; col<j; col++){
            printf("%d " , matrix[row][col]);
        }
        printf("\n");
    }
}