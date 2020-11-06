// Write a program to find length of a given string

#include<stdio.h>

int main(){
    char str[50000];
    printf("Enter String: ");
    scanf("%[^\n]c* ", str);
    int len=0;
    while(str[len++]!='\0');
    printf("Length of the string is %d.\n", len-1);
    return 0;
}