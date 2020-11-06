/*
Q.a)    Write a program to multiply two given matrices.
*/

#include<stdio.h>

int main(){
    int m1, n1, m2, n2;
    printf("Enter m and n for mxn matrix A :");
    scanf("%d %d", &m1, &n1);
    int A[m1][n1];
    printf("Enter Matric A: \n");
    for(int i=0; i<m1; i++){
        for(int j=0; j<n1; j++) scanf("%d", &A[i][j]);
    }
    printf("Enter m and n for mxn matrix B :");
    scanf("%d %d", &m2, &n2);
    int B[m2][n2];
        printf("Enter Matric B: \n");
    for(int i=0; i<m2; i++){
        for(int j=0; j<n2; j++) scanf("%d", &B[i][j]);
    }
    if(n1==m2){
        int ans[m1][n2];
        for(int i=0; i<m1; i++){
            for(int j=0; j<n2; j++) {
                ans[i][j]=0;
                for(int k=0; k<n1; k++){
                    ans[i][j]+=A[i][k]*B[k][j];
                }
            }
        }
        printf("The Resultant matrix A*B is: \n");
        for(int i=0; i<m1; i++){
            for(int j=0; j<n2; j++) {
                printf("%d ", ans[i][j]);
            }
            printf("\n");
        }
    }else{
        printf("Matrices are not multipliable. Aborting!!\n");
    }
    return 0;
}