/*
    Write a C program to add and subtract two integers having at least 10 digits each.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char* reverse(char* str,int n)
{
	char temp;
	for(int i=0;i<n/2;i++){
		temp=str[i];
		str[i]=str[n-1-i];
		str[n-1-i]=temp;
	}
	return str;
}

int main()
{
	char a[1000], b[1000], sumAns[1000], diffAns[1000];
	int n1, n2, i, m=0, l=0, c=0, sum, diff, swapped = 0;
	printf("Enter First Number(a): ");
	scanf("%s",a);
	printf("Enter Second Number(b): ");
	scanf("%s",b);
	n1=strlen(a),n2=strlen(b);
	if(n1<n2){
		char tem[1000]; 
		strcpy(tem, a); 
  		strcpy(a, b); 
  		strcpy(b, tem);
		swapped = 1;
		int temp  = n1;
		n1 = n2;
		n2 = temp;
	}
	else if(n1==n2 && strcmp(a,b)<0)
	{
		char tem[1000]; 
		strcpy(tem, a); 
  		strcpy(a, b); 
  		strcpy(b, tem);
		swapped=1;
	}
	reverse(a,n1);
	reverse(b,n2);

	for(i=0; i<n1; i++)
	{
		if(i<n1 && i<n2)
		{
			sum =m+a[i]-'0'+b[i]-'0';
			diff=l+(a[i]-'0')-(b[i]-'0');
		}
		else if(i>=n2)
		{
			sum=m+(a[i]-'0');
			diff=l+(a[i]-'0');
		}
		sumAns[i] = sum%10 + '0';
		m=sum/10;
		diffAns[i]=(diff>=0?diff:diff+10) + '0';
		l=(diff>=0?0:-1);
	}
	diffAns[i] = '\0'; 
	if(m==1)
		sumAns[i]=m + '0',i++;
	sumAns[i] = '\0';
	if(swapped) strcat(diffAns,"-");


	reverse(sumAns, strlen(sumAns));
	reverse(diffAns, strlen(diffAns));
	printf("Sum (a + b) = %s\n", sumAns);
	printf("Difference (a - b) = %s\n", diffAns);
	return 0;
}
