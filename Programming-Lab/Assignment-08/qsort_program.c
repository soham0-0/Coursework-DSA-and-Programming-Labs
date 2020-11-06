/*
    1.  Explore qsort() function. Use qsort() to sort a set of integers and 
        a set floating point numbers in ascending order by a single program.
*/

#include <stdio.h>
#include <stdlib.h>

int intComparator(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int floatComparator(const void *a, const void *b){
    return *(float*)a - *(float*)b > 0.0 ? 1 : -1; 
}

int main(){
    printf("Enter the number of elements to add in integer array: ");
    int n;
    scanf("%d", &n);
    printf("Enter %d  integer elements: ", n);
    int a[n];
    for(int i=0; i<n; i++)  scanf(" %d", &a[i]);
    qsort(a, n, sizeof(int), intComparator);
    printf("Sorted Array: \n");
    for(int i=0; i<n; i++)  printf("%d ", a[i]);
    printf("\n\n");
    printf("Enter the number of elements to add in floating point array: ");
    scanf("%d", &n);
    printf("Enter %d float elements: ", n);
    float b[n];
    for(int i=0; i<n; i++)  scanf(" %f", &b[i]);
    qsort(b, n, sizeof(float), floatComparator);
    printf("Sorted Array: \n");
    for(int i=0; i<n; i++)  printf("%f ", b[i]);
    printf("\n");
    return 0;
}