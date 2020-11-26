/*
    1.  Your input is a positive integer n, followed by an n × n square matrix A with each cell
        filled with a digit between 0 and 9. Write a program to display A in the terminal rotated
        clockwise at an angle of 45 o as shown in the example below.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 500

char *strrev(char *str) {
    char *p1, *p2;
    if (! str || ! *str) return str;
    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2) {
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
    return str;
}

int main(){
    int n; scanf(" %d", &n);
    int a[SIZE][SIZE];
    
    //  Input matrix
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            scanf(" %d", &a[i][j]);
        }
    }
    int len[2*n - 1];   //  length container for strings
    memset(len, 0, (2*n - 1)*sizeof(int));  //  initializing length at 0
    char strings[2*n-1][SIZE];  //  strings[i] is ith row of the pattern (0 indexing)
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            //  appending character of the diagonal and a space to the (i+j)th diagonal string
            strings[i+j][len[i+j]++] = '0' + a[i][j];
            strings[i+j][len[i+j]++] = ' ';
        }
    }

    //  Printing Required pattern
    for(int i=0; i<2*n - 1; ++i){
        strings[i][len[i]++] = '\0';
        for(int j=0; j<abs(n - i - 1); ++j) printf(" ");
        puts(strrev(strings[i]));
    }
    return 0;
}