/*
    Write a program in C to represent a sparse matrix of order n x n efficient way in respect of space.
*/

#include<stdio.h>

struct matrix{
    int mag;
    int x;
    int y;
};

int main(){
    printf("Enter n: ");
    int n;
    scanf("%d", &n);
    int a[n][n],s=0;
    printf("Enter elements of a sparse matrix row wise: \n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++){
            scanf("%d", &a[i][j]);
            if(a[i][j]) s++;
        }
    }

    struct matrix mat[s];
    int p=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(a[i][j]){
                mat[p].mag = a[i][j];
                mat[p].x = i;
                mat[p].y = j;
                p++;
            } 
        }
    }

    printf("The given matrix: \n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    printf("Space efficient representation => ( value of element, x-coordinate, y-coordinate): \n");
    for(int i=0; i<s; i++){
        printf("( %d, %d, %d)  ", mat[i].mag, mat[i].x, mat[i].y);
    }
    printf("\n");
    return 0;
}