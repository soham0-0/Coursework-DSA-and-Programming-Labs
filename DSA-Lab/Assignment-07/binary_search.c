/*
    4.  Write a C Program for binary search or half-interval search algorithm to
        find a target value within a sorted array.
*/

#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main(){
    int n; printf("Enter the number of elements: ");
    scanf(" %d", &n);
    int arr[n];
    puts("Enter elements of array");
    for(int i=0; i<n; ++i) scanf(" %d", &arr[i]);
    qsort(arr, n, sizeof(int), cmpfunc);
    int target; printf("Enter target value: ");
    scanf(" %d", &target);
    int l = 0, r = n-1, mid;
    while(l<=r){
        mid = (l + r)/2;
        if(arr[mid] > target) r = mid - 1;
        else if(arr[mid] < target) l  = mid + 1;
        else break;
    }
    if(arr[mid] == target) printf("%d is present in the array.\n", target);
    else printf("%d not found\n", target);
    return 0;
}