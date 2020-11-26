/*
Q2: Do the addition and subtraction of two nxn sparse matrices using the efficient
    representation of the matrix done in the previous Assignment 1.
*/

#include<stdio.h>
#include<stdbool.h>

// structure for efficient representation
struct matrix{
    int mag;
    int x;
    int y;
};

int main(){
    printf("Enter n: ");
    int n;
    scanf("%d", &n);
    int a[n][n],s1=0, s2=0;
    printf("Enter elements of a sparse matrix 1 row wise: \n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++){
            scanf("%d", &a[i][j]);
            if(a[i][j]) s1++;
        }
    }

    struct matrix mat1[s1];
    int p=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(a[i][j]){
                mat1[p].mag = a[i][j];
                mat1[p].x = i;
                mat1[p].y = j;
                p++;
            } 
        }
    }

    printf("Efficient representation of mat1 => ( value of element, x-coordinate, y-coordinate): \n");
    for(int i=0; i<s1; i++){
        printf("( %d, %d, %d)  ", mat1[i].mag, mat1[i].x, mat1[i].y);
    }
    printf("\n");

    
    printf("\nEnter elements of a sparse matrix 2 row wise: \n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++){
            scanf("%d", &a[i][j]);
            if(a[i][j]) s2++;
        }
    }

    struct matrix mat2[s2];
    p=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(a[i][j]){
                mat2[p].mag = a[i][j];
                mat2[p].x = i;
                mat2[p].y = j;
                p++;
            } 
        }
    }
    printf("Efficient representation mat2 => ( value of element, x-coordinate, y-coordinate): \n");
    for(int i=0; i<s2; i++){
        printf("( %d, %d, %d)  ", mat2[i].mag, mat2[i].x, mat2[i].y);
    }
    printf("\n");

    // sum and difference logic
    struct matrix sum[s1+s2], diff[s1+s2];
    int sumLen=0, diffLen=0,i=0,j=0;            // i and j are indices for mat1 and mat2
    while(i<s1 || j<s2){
        if(i>=s1){
            sum[sumLen].x=mat2[j].x;
            sum[sumLen].y=mat2[j].y;
            sum[sumLen++].mag=mat2[j].mag;
            diff[diffLen].x=mat2[j].x;
            diff[diffLen].y=mat2[j].y;
            diff[diffLen++].mag=-1*mat2[j].mag;
            j++;
            continue;
        }
        else if(j>=s2){
            sum[sumLen].x=mat1[i].x;
            sum[sumLen].y=mat1[i].y;
            sum[sumLen++].mag=mat1[i].mag;
            diff[diffLen].x=mat1[i].x;
            diff[diffLen].y=mat1[i].y;
            diff[diffLen++].mag=mat1[i].mag;
            i++;
            continue;
        }
        if(n*mat1[i].x + mat1[i].y == n*mat2[j].x + mat2[j].y){
            sum[sumLen].x=mat1[i].x;
            sum[sumLen].y=mat1[i].y;
            sum[sumLen++].mag=mat1[i].mag+mat2[j].mag;
            diff[diffLen].x=mat1[i].x;
            diff[diffLen].y=mat1[i].y;
            diff[diffLen++].mag=mat1[i].mag-mat2[j].mag;
            i++; j++;
        }
        else if(n*mat1[i].x + mat1[i].y < n*mat2[j].x + mat2[j].y){
            sum[sumLen].x=mat1[i].x;
            sum[sumLen].y=mat1[i].y;
            sum[sumLen++].mag=mat1[i].mag;
            diff[diffLen].x=mat1[i].x;
            diff[diffLen].y=mat1[i].y;
            diff[diffLen++].mag=mat1[i].mag;
            i++;
        }
        else {
            sum[sumLen].x=mat2[j].x;
            sum[sumLen].y=mat2[j].y;
            sum[sumLen++].mag=mat2[j].mag;
            diff[diffLen].x=mat2[j].x;
            diff[diffLen].y=mat2[j].y;
            diff[diffLen++].mag=-1*mat2[j].mag;
            j++;
        }
    }

    printf("\nEfficient representation Sum Matrix (Sum = Mat1 + Mat2) => ( value of element, x-coordinate, y-coordinate): \n");
    for(int i=0; i<sumLen; i++){
        printf("( %d, %d, %d)  ", sum[i].mag, sum[i].x, sum[i].y);
    }
    int t=0;
    printf("\nNormal representation of Sum Matrix (Sum = Mat1 + Mat2): \n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++){
            if(n*i + j == n*sum[t].x + sum[t].y) {
                printf("%d ", sum[t++].mag);
            }
            else printf("0 ");
        }
        printf("\n");
    }
    printf("\n");

    printf("\nEfficient representation Difference Matrix (Diff = Mat1 - Mat2) => ( value of element, x-coordinate, y-coordinate): \n");
    for(int i=0; i<diffLen; i++){
        printf("( %d, %d, %d)  ", diff[i].mag, diff[i].x, diff[i].y);
    }
    printf("\n");
    t=0;
    printf("Normal representation of Difference Matrix (Diff = Mat1 - Mat2): \n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++){
            if(n*i + j == n*diff[t].x + diff[t].y) {
                printf("%d ", diff[t++].mag);
            }
            else printf("0 ");
        }
        printf("\n");
    }
    printf("\n");


    return 0;
}
