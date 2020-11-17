/*
    2.  Write a C Program which will take the elements from the command line
        and sort them by the Marge Sort algorithm.
*/
#include <stdio.h>
#include <stdlib.h>

void mergeSort(int*, int, int);

int main() {
    int n; printf("Enter number of elements: ");
    scanf(" %d", &n);
    int arr[n];
    puts("Enter elements of the array: ");
    for(int i=0; i<n; ++i) scanf(" %d", &arr[i]);
	mergeSort(arr, 0, n - 1);

	printf("Sorted array: ");
    for(int i=0; i<n; ++i) printf("%d ", arr[i]);
    puts("");
	return 0;
}

void mergeSort(int arr[], int l, int r) {
	if (l < r) {
		int mid = l + (r - l) / 2;
		mergeSort(arr, l, mid); mergeSort(arr, mid + 1, r);
		int n1 = mid - l + 1, n2 = r - mid, arr1[n1], arr2[n2];
		for (int i = 0; i < n1; i++) arr1[i] = arr[l + i];
		for (int j = 0; j < n2; j++) arr2[j] = arr[mid + 1 + j];
		int i = 0, j = 0, k = l;
		while (i < n1 && j < n2){
			if(arr1[i]<arr2[j]) arr[k++] = arr1[i++];
			else arr[k++] = arr2[j++];
		}
		while (i < n1) arr[k++] = arr1[i++];
		while (j < n2) arr[k++] = arr2[j++];
	}
}
