/*
    Write a program in C to find the third largest from the given array of integers without
sorting.
*/

#include<stdio.h>

int main(){
    int n;
    printf("Enter number of elements of array: ");
    scanf("%d",&n);
    int a[n], max=0, max1=0, max2=0;
    printf("Enter Array: ");
    for(int i = 0; i<n; i++){
        scanf("%d",&a[i]);

        if(max<a[i]){
            max1=max;
            max=a[i];
        }
        else if(max1<a[i]){
            max2=max1;
            max1=a[i];
        }
        else if(max2<a[i]){
            max2=a[i];
        }
    }
    if(n<3) printf("Array contains less than 3 elements.");
    else printf("Third max in array is %d.\n",max2);

    return 0;
}