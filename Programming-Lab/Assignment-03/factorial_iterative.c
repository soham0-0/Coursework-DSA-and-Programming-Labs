// factorial using for loop

#include<stdio.h>

double fact(double n){
    double ans=1;
    for(int i=1; i<=n; i++){
        ans*=i;
    }
    return ans;
}

int main(){
    double n;
    printf("Enter no.: ");
    scanf("%lf",&n);
    printf("%lf! = %lf\n", n, fact(n));
    return 0;
}