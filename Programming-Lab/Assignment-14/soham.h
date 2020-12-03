#ifndef SOHAM_H     //  Include guard
#define SOHAM_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char *str){
    int n = strlen(str), l = 0, r = n - 1;
    while(l < r){
        if(str[l] != str[r]) return false;
        ++l; --r;
    }
    return true;
}

bool isPrime(int n){
    for(int i=2; i*i <= n; ++i){
        if(n%i == 0) return false;
    }
    return true;
}

double factorial(int n){
    if(n == 1) return 1;
    return n*factorial(n-1);
}

#endif