// factorial using recursive function
#include<stdio.h>

double fact(double n){
    if(n>=1) return  n*fact(n-1);
    return 1;
}

int main(){
    double n;
    printf("Enter no.: ");
    scanf("%lf",&n);
    printf("%lf! = %lf\n", n, fact(n));
    return 0;
}