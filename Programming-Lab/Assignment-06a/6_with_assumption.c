/  Solve Assignment 6 by assuming n=4.

#include<stdio.h>
#include<stdlib.h>

#define SIZE 25
void multiply(int mat1[][SIZE], int mat2[][SIZE], int mult[][SIZE], int r1, int c1, int r2, int c2);
void display(int mult[][SIZE], int r1, int c2);

int main(){
    printf("Enter 4 matrices: \n");
    int mat[4][SIZE][SIZE], m[4], n[4];
    for(int i=0; i<4; i++){
        printf("Enter dimensions m X n:\nm: ");
        scanf(" %d", &m[i]);
        printf("n: ");
        scanf(" %d", &n[i]);
        for(int p = 0; p<m[i]; p++){
            for(int q = 0; q<n[i]; q++) scanf(" %d", &mat[i][p][q]);
        }
    }
    char order[5][2*(SIZE-1)] = {
        "((AB)C)D",
        "(A(BC))D",
        "(AB)(CD)",
        "A((BC)D)",
        "A(B(CD))"
    };
    
    int scalerMults[5] = {0}, minScalarMults = 0, ind = 0; 

    printf("For the order: %s \n", order[0]);
    int res1[SIZE][SIZE], res[SIZE][SIZE];
    multiply(mat[0], mat[1], res1, m[0], n[0], m[1], n[1]);
    scalerMults[0] += m[0]*n[0]*n[1]; 
    multiply(res1, mat[2], res, m[0], n[1], m[2], n[2]);
    scalerMults[0] += m[0]*n[1]*n[2];
    multiply(res, mat[3], res1, m[0], n[2], m[3], n[3]);
    scalerMults[0] += m[0]*n[2]*n[3];
    minScalarMults = scalerMults[0];
    printf("number of scaler multiplications are %d.\n", scalerMults[0]);
    display(res1, m[0], n[3]);
    
    printf("For the order: %s ", order[1]);
    multiply(mat[1], mat[2], res1, m[1], n[1], m[2], n[2]);
    scalerMults[1] += m[1]*n[1]*n[2];
    multiply(mat[0], res1,  res, m[0], n[0], m[1], n[2]);
    scalerMults[1] += m[0]*n[0]*n[2];
    multiply(res, mat[3], res1, m[0], n[2], m[3], n[3]);
    scalerMults[1] += m[0]*n[2]*n[3];
    if(minScalarMults > scalerMults[1]){  minScalarMults = scalerMults[1]; ind = 1; }
    printf("number of scaler multiplications are %d.\n", scalerMults[1]);
    display(res1, m[0], n[3]);
    
    printf("For the order: %s \n", order[2]);
    int res2[SIZE][SIZE];
    multiply(mat[0], mat[1], res1, m[0], n[0], m[1], n[1]);
    scalerMults[2] += m[0]*n[0]*n[1];
    multiply(mat[2], mat[3], res, m[2], n[2], m[3], n[3]);
    scalerMults[2] += m[2]*n[2]*n[3];
    multiply(res1, res, res2, m[0], n[1], m[2], n[3]);
    scalerMults[2] += m[0]*n[1]*n[3];
    if(minScalarMults > scalerMults[2]){  minScalarMults = scalerMults[2]; ind = 2; }
    printf("number of scaler multiplications are %d.\n", scalerMults[2]);
    display(res2, m[0], n[3]);
    
    printf("For the order: %s \n", order[3]);
    multiply(mat[1], mat[2], res, m[1], n[1], m[2], n[2]);
    scalerMults[3] += m[1]*n[1]*n[2];
    multiply(res, mat[3], res1, m[1], n[2], m[3], n[3]);
    scalerMults[3] += m[1]*n[2]*n[3];
    multiply(mat[0], res1, res, m[0], n[0], m[1], n[3]);
    scalerMults[3] += m[0]*n[0]*n[3];
    if(minScalarMults > scalerMults[2]){  minScalarMults = scalerMults[2]; ind = 2; }
    printf("number of scaler multiplications are %d.\n", scalerMults[2]);
    display(res, m[0], n[3]);
    
    printf("For the order: %s \n", order[4]);
    multiply(mat[2], mat[3], res, m[2], n[2], m[3], n[3]);
    scalerMults[4] += m[2]*n[2]*n[3];
    multiply(mat[1], res, res1, m[1], n[1], m[2], n[3]);
    scalerMults[4] += m[1]*n[1]*n[3];
    multiply(mat[0], res1, res, m[0], n[0], m[1], n[3]);
    scalerMults[4] += m[0]*n[0]*n[2];
    if(minScalarMults > scalerMults[2]){  minScalarMults = scalerMults[2]; ind = 2; }
    printf("number of scaler multiplications are %d.\n", scalerMults[2]);
    display(res, m[0], n[3]);

    printf("Minimum number of scalar multiplications is %d for the order %s. \nAnd since all final matrices are same, we can conclude matrix multiplication is associative. \n", minScalarMults, order[ind]);

}

void multiply(int mat1[][SIZE], int mat2[][SIZE], int mult[][SIZE], int r1, int c1, int r2, int c2)
{
    if(c1 != r2){
        printf("Invalid!\n");
        exit(0);
    }
	int i, j, k;
	for(i = 0; i < r1; ++i)
	{
		for(j = 0; j < c2; ++j)
		{
			mult[i][j] = 0;
		}
	}

	for(i = 0; i < r1; ++i)
	{
		for(j = 0; j < c2; ++j)
		{
			for(k=0; k<c1; ++k)
			{
				mult[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}
}

void display(int mult[][SIZE], int r1, int c2)
{
	int i, j;
	printf("Output Matrix:\n");
	for(i = 0; i < r1; ++i)
	{
		for(j = 0; j < c2; ++j)
		{
			printf("%d  ", mult[i][j]);
			if(j == c2 - 1)
				printf("\n");
		}
	}
}