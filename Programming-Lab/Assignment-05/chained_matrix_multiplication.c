/*
Q.b)    Write another program to multiply a chain of matrices. Use a function to multiply two matrices which is to be called from the main.
*/

#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

bool multiply(int m1, int n1, int m2, int n2,int A[][100], int B[][100], int ans[][100]){
    if(n1==m2){
        for(int i=0; i<m1; i++){
            for(int j=0; j<n2; j++) {
                ans[i][j]=0;
                for(int k=0; k<n1; k++){
                    ans[i][j]+=A[i][k]*B[k][j];
                }
            }
        }
        return true;
    }else{
        return false;
    }
}


int main(){
    char exp[60]="A",c[2]="B";
    int m0,n0;
    printf("Enter m and n for mxn matrix A :");
    scanf("%d %d", &m0, &n0);
    int A[100][100], mat[100][100], ans[100][100];  //  maximum size 100x100
    printf("Enter Matric A: \n");
    for(int i=0; i<m0; i++){
        for(int j=0; j<n0; j++) scanf("%d", &A[i][j]);
    }
    char k;
    do{
        int m,n;
        printf("Enter m and n for mxn matrix %s :", c);
        scanf("%d %d", &m, &n);
        printf("Enter Matric %s: \n", c);
        strcat(exp, "*");
        strcat(exp, c);
        c[0]++;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++) scanf("%d", &mat[i][j]);
        }
        if(multiply(m0,n0,m,n,A,mat,ans)){
            printf("The Resultant matrix %s is: \n", exp);
            for(int i=0; i<m0; i++){
                for(int j=0; j<n; j++) {
                    A[i][j]=ans[i][j];
                    printf("%d ", ans[i][j]);
                }
                printf("\n");
            }
            n0=n;
        }else{
            printf("Matrices are not multipliable. Aborting!!\n");
            exit(0);
        }

        printf("Do you want to chain more matrices to the multiplication? (y/n): ");
        scanf(" %c",&k);
    }while(k=='y'||k=='Y');
    
    return 0;
}