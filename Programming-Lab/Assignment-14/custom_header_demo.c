/*
    Develop a header file by your own. Put all the functions (and other header files) that you want to use in your program in that file. 
    Then write a program that contains only the main() function and calls the other functions of the header file. 
    In the program, only the header file that you have developed is to be included.
*/

#include "soham.h"

int main(){
    while(true){
        printf("1. Enter a string and check if it is a palindrome.\n2. Enter a number and check if it is a prime or not.\n3. Enter a number and calculate its factorial\n0. Exit Program.\nEnter choice (0 - 3): ");
        int c; scanf(" %d", &c);
        if(c == 0) break;
        switch (c) {
            case 1: {
                char str[100];
                scanf(" %s", str);
                if(isPalindrome(str)) puts("String is a Palindrome.");
                else puts("String is not a Palindrome.");
                break;
            }
            case 2: {
                int n;
                scanf(" %d", &n);
                if(n == 1){
                    puts("Number is neither prime nor composite");
                    break;
                }
                if(isPrime(n)) puts("Number is a Prime.");
                else puts("Number is Composite.");
                break;
            }
            case 3: {
                int n;
                scanf(" %d", &n);
                printf("%lf\n", factorial(n));
                break;
            }
            default:
                puts("Wrong Choice! Try Again!");
                break;
        }
    }
    return 0;
}