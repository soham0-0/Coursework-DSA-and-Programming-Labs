/*
    Write a program to check if a string is palindrome  or not?
*/

#include<stdio.h>
#include<string.h>

int main(){
    char str[1000];
    scanf("%[^\n]*c", str);
    int i=0, j=strlen(str)-1,k=0;
    while(i<j){
        if(str[i]!=str[j]){
            k++;
            break;
        }
        i++;
        j--;
    }
    if(k) printf("No\n");
    else printf("Yes\n");
    return 0;
}
