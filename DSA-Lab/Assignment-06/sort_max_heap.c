/*
    4.  Write a C Program to implement the Max Heap and then delete all the elements from the
        tree so that the deleted elements are in sorted order.
*/

#include <stdio.h>
#include <limits.h>

void swap(int *a, int *b);
void heapify(int arr[], int n, int i);
void buildHeap(int arr[], int n);

int main(){
    int n; printf("Enter number of elements: ");
    scanf(" %d", &n);
    int arr[n];
    printf("Enter elements of the array: ");
    for(int i=0; i<n; ++i) scanf(" %d", &arr[i]);
    buildHeap(arr, n);
    printf("Max Heap : ");
    for(int i=0; i<n ; ++i) printf("%d ", arr[i]);
    printf("\nDeleting elements to sort: \n");
    while(n){
        buildHeap(arr, n);
        printf("%d ", arr[0]);
        arr[0] = arr[--n];
    }
    puts("");
    
    return 0;
}

void heapify(int arr[], int n, int i) {
    int max = i, l = 2*i + 1, r = 2*i + 2;
    if (l < n && arr[l] > arr[max]) max = l;
    if (r < n && arr[r] > arr[max]) max = r;
    if (max != i) {
        int tem = arr[i];
        arr[i] = arr[max];
        arr[max] = tem;
        heapify(arr, n, max);
    }
}

void buildHeap(int arr[], int n) { 
    int start = (n/2) - 1;
    for(int i = start; i >= 0; --i) heapify(arr, n, i); 
}