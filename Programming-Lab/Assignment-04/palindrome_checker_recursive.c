/*
    Write a program to check a given string as palindrome by developing a recursive function that takes only two character pointers, pointing to two locations, as argument.
*/

#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool isPalindrome(char *a, char*b){
    if(a>=b) return true;
    else if(*a!=*b) return false;
    return isPalindrome(a+1, b-1);
}

int main(){
    char str[100];
    scanf("%[^\n]*c", str);
    if(isPalindrome(str, str+strlen(str)-1)) printf("Palindrome.\n");
    else printf("Not Palindrome.\n");
}