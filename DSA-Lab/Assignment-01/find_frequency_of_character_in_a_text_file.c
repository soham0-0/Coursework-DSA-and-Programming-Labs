/*
    Write a C program to find the frequency of a character present in the text given in a file.
*/

#include<stdio.h>

int main(){
    char path[100], c;
    int count = 0;
    printf("Enter file path: ");
    scanf("%[^\n]*c", path);
    printf("Enter character you want to know the frequency of: ");
    scanf(" %c",&c);

    FILE *f;
    if((f = fopen(path, "r"))==NULL) {
        printf("Error in opening file. Aborting!\n");
        return -1;
    }
    else {
        char k = getc(f);
        while(!feof(f)) {
            if(c==k) count++;
            k = getc(f);
        }
    }
    fclose(f);

    printf("The frequency of '%c' is %d\n", c, count);

    return 0;
}