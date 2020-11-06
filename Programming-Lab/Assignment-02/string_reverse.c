// Write a program to reverse a a given string.

#include <stdio.h> 

int main() 
{ 
	char str[5000]; 
	printf("Enter the String: "); 
	scanf("%[^\n]c* ", str);
    int i=0,n=0;
    while(str[n++]!='\0');
    n--;
    while(i<n/2) {
        char c = str[i];
        str[i] = str[n-i-1];
        str[n-i-1] = c;
        i++;
    }
     
    printf("Reversed string: %s\n", str);

	return 0; 
} 