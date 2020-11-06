/*
    2.  Design a set of functions (such as ADD, DIV, POWER (to do x^y), etc.) of your choice and 
        store them in an array of function pointers. Write a program that will use these functions
        from the array, based on the user input. DO NOT USE switch-case/if-else to solve this problem. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int findNumberOfPrimes(int a, int b);
int findNumberOfComposites(int a, int b);
int LShift(int a, int b);
int RShift(int a, int b);
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divde(int a, int b);
int power(int a, int b);

int main(){
    int (*fn[9])(int a, int b) = {findNumberOfPrimes, findNumberOfComposites, LShift, RShift, add, subtract, multiply, divde, power};
    printf("Enter a and b: ");
    int a,b; scanf("%d %d", &a, &b);
    puts("1. Find the number of prime numbers in the range [min(a,b), max(a,b)]");
    puts("2. Find the number of composite numbers in the range [min(a,b), max(a,b)]");
    puts("3. Compute a<<b");
    puts("4. Compute a>>b");
    puts("5. Compute a+b");
    puts("6. Compute a-b");
    puts("7. Compute a*b");
    puts("8. Compute a/b");
    puts("9. Compute a^b");
    printf("Enter choice (1-9): ");
    int ch; scanf(" %d", &ch);
    if(ch>9 || ch<1){
        puts("INVALID CHOICE");
        return 1;
    } 
    printf("Output = %d\n", fn[ch-1](a, b));
    return 0;
}



int findNumberOfPrimes(int a, int b){
    if(a>b){
        int tem = a;
        a = b;
        b = tem;
    }
    int ans = 0;
    for(int i=a; i<=b; ++i){
        bool prime = true; 
        for(int j=2; j<i; ++j){
            if(i%j == 0){
                prime = false;
                break;
            }
        }
        if(prime) ans++;
    }
    return ans;
}

int findNumberOfComposites(int a, int b){
    return (b - a + 1) - findNumberOfPrimes(a, b);
}

int LShift(int a, int b){
    return a<<b;
}

int RShift(int a, int b){
    return a>>b;
}

int add(int a, int b) {
    return a+b;
}

int subtract(int a, int b){
    return a-b;
}

int multiply(int a, int b){
    return a*b;
}

int divde(int a, int b){
    if(b==0){
        printf("DIVIDE BY 0 ERROR!!\n");
        exit(0);
    }
    return a/b;
}

int power(int a, int b){
    return pow(a, b);
}