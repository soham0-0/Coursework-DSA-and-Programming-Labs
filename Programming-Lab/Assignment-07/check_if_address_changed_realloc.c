/*
    2.  Use realloc() to reallocate a block of memory (for example, a
        matrix), which has already been allocated by malloc() or
        calloc(), with new size. Check if the address (addresses) of the
        old block has been changed due to the use of realloc(). Perform
        a good number of experiments before reaching to a conclusion.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Enter the length (n) of the integer array to be allocated: ");
    scanf("%d", &n);
    int *a = (int *)malloc(n*sizeof(int));
    int *tem = a;
    printf("Current Memory block address: %0x\n\n", a);
    printf("Enter the new length (n) of the integer array: ");
    scanf("%d", &n);
    a = (int *)realloc(a, n*sizeof(int));
    printf("Current Memory block address: %0x\n\n", tem);
    if(tem==a){
        printf("Memory Location Unchanged.\n");
    }
    else {
        printf("Memory Location Changed.\n");
    }
    return 0;
}

/*
Conclusion: As it is evident from the outputs, if the difference between allocation size and reallocation size is too great, 
            the address of the memory block changes otherwise it doesn't change. This is because if there  is not enough space 
            after the current memory block then the realloc funtion changes the location of the block to somewhere else,
            where the required amount of memory is available.
*/