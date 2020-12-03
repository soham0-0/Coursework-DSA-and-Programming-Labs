/*
    Write a program using a function which takes variable number of arguments (like printf(), scanf(), etc). 
    You may design any function by your own, such as searching a key from a set of values, 
    where the search key and the set of values are passed as arguments.

    Function Implemented: Average
*/

#include <stdio.h>
#include <stdarg.h>

double avg(int, ...);

int main() {
    printf("Average of 10 numbers [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]: %lf\n", avg(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10));
    printf("Average of 2 numbers [55, 58]: %lf\n", avg(2, 55, 58));
}

double avg(int count, ...) {
    va_list valist;
    double sum = 0.0;
    va_start(valist, count);
    for(int i = 0; i < count; i++)  sum += va_arg(valist, int);
    va_end(valist);
    return sum/count;
}