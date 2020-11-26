/*
    Given an array of n integers, write a C program for reversing the contents of the array without using another array.
*/

#include<stdio.h>

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int a[n];

    printf("Enter array: \n");
    for(int i=0; i<n; i++) scanf("%d",&a[i]);

    for(int i=0; i<n/2; i++){
        a[i] = a[i] + a[n-i-1];
        a[n-i-1] = a[i] - a[n-i-1];
        a[i] = a[i] - a[n-i-1];
    }

    printf("The reversed array is ");
    for(int i=0; i<n; i++){
        printf("%d ",a[i]);
    }
    printf("\n");

    return 0;
}
