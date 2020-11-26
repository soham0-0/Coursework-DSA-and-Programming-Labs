/*
Q1: Write a program to read the string of 0s and 1s from a given file. Then do the following.
    a.  Break the string into the substrings ending with 1 and of length of consecutive n
        number of 0s or 1s. N can be 2, 3 and 4.
    b.  Count the frequency of each substring. Calculate the length of the string using
        frequency and verify with the original string length.
    c.  Replace each pattern substring with a character starting from A (for substring of
        length 1), B(for substring with length 2) etc. and put the characters in a separate
        file based on the position of the substring in the original string.
    d.  Calculate the length of the new string and calculate the % reduction of length.
*/

#include<stdio.h>
#include<string.h>

int main(){
    char path[100];
    int n;
    printf("Enter file path: ");
    scanf("%[^\n]*c", path);
    printf("Enter n: ");
    scanf("%d", &n);
    printf("\n");


    FILE *f;
    if((f = fopen(path, "r"))==NULL) {
        printf("Error in opening input file. Aborting!\n");
        return -1;
    }
    int cnt=0, patFreq[1002]={0};           // patFreq is for frequency calculation of substrings and cnt is the length of said substring
    char str[1000], s[1000];                // s is replaced string
    while (fgets(str, 1000, f) != NULL){
        int len = strlen(str),cur=0;        // cur is the length of current substring
        char tem[n+1];                      // tem is current substring
        // seggregating and counting substrings
        printf("Substrings:\n");
        for(int i=0; i<len; i++){
            if(cur==n){
                tem[cur]='\0';
                printf("%s", tem);
                int k = 0;
                if(tem[0]=='1') k=1;
                patFreq[cur+k]++;
                s[cnt++]='A'+cur+k;
                cur=0;                      // setting current substring length at 0 when previous substring ends
                if(len-i>n) printf(", ");
             }
            if(cur!=0 && tem[cur-1]!=str[i]){
                if(str[i]=='1') tem[cur++]='1';
                else i--;
                tem[cur]='\0';
                printf("%s", tem);
                patFreq[cur-1]++;
                s[cnt++]='A'+cur-1;
                cur=0;
                if(len-i>n) printf(", ");
            }
            else tem[cur++]=str[i];
        }
    }
    s[cnt]='\0';
    fclose(f);
    
    printf("\n");
    int sp=(n-10>4 )?(n-10):(5);            // sp is space count for formatting purpose 
    printf("\nSubstring:");
    for(int i=0; i<sp;i++) printf(" ");
    printf("Frequency:\n");
    for(int i=0; i<sp+20; i++) printf("-");
    printf("\n");
    int total=0;
    for(int i=0; i<n+2; i++){
        if(i<n){
            int k=i;
            while(k--) printf("0");
            printf("1");
            for(int j=0; j<sp-i+9; j++) printf(" ");
            printf("%d\n", patFreq[i]);
            total+=(i+1)*patFreq[i];
        }
        else if(i==n){
            int k=n;
            while(k--) printf("0");
            for(int j=0; j<sp-n+10; j++) printf(" ");
            printf("%d\n", patFreq[i]);
            total+=(n)*patFreq[i];
        }
        else {
            int k=n;
            while(k--) printf("1");
            for(int j=0; j<sp-n+10; j++) printf(" ");
            printf("%d\n", patFreq[i]);
            total+=(n)*patFreq[i];
        }
    }
    for(int i=0; i<sp+20; i++) printf("-");
    printf("\nTotal Length");
    for(int i=0; i<sp-4;i++) printf(" ");
    printf("= %d\n",total );                // printing total length computed by frequency

    printf("\n");
    FILE *fp;
    if((fp = fopen("shortenedBinNum.txt", "w"))==NULL) {
        printf("Error in opening output file. Aborting!\n");
        return -1;
    }
    fputs(s, fp);
    fclose(fp);
    str[strlen(str)-1]='\0';
    printf("Replaced string '%s' has been saved in 'shortenedBinNum.txt'\n", s);
    printf("Initial length ie length of '%s' = %ld\nShortend length ie length of '%s' = %ld\nPercent reduction = %f%%\n",str,strlen(str),s,strlen(s),100.0*(float )(strlen(str)-strlen(s))/(float )strlen(str));
    return 0;
}
