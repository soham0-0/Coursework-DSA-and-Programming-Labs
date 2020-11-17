/*
    3.  Write a C Program which will take the elements from the terminal and sort
        them by the Quick Sort algorithm.
*/

#include <stdio.h>
#include <stdlib.h>

void quickSort(int *, int);

int main() {
    int n; printf("Enter number of elements: ");
    scanf(" %d", &n);
    int arr[n];
    puts("Enter elements of the array: ");
    for(int i=0; i<n; ++i) scanf(" %d", &arr[i]);
	quickSort(arr, n);

	printf("Sorted array: ");
    for(int i=0; i<n; ++i) printf("%d ", arr[i]);
    puts("");
	return 0;
}

void quickSort(int arr[], int n) {  // taking rightmost element as pivot
    if(n<=1) return ;
    int pivot = arr[n-1], left[n-1], right[n-1], l = 0, r = 0;
    for(int i=0; i<n-1; ++i){
        if(arr[i] < pivot) left[l++] = arr[i];
        else right[r++] = arr[i];
    }
    quickSort(left, l); quickSort(right, r);
    for(int i=0; i<l; ++i) arr[i] = left[i];
    arr[l] = pivot;
    for(int i=0; i<r; ++i) arr[l+i+1] = right[i];
}