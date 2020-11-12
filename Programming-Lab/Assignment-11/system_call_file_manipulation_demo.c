/*
    2.  Write a program using these five functions to count the numbers of characters in a file. 
        If the number is even then append two arbitrary characters; otherwise append single character in that file.
*/

#include <stdio.h> 
#include <time.h>
#include <stdlib.h>
#include <string.h> 
#include <unistd.h> 
#include <fcntl.h> 

int main(){
    char file[100];
    write(1, "Enter file name (max 100 characters): ", strlen("Enter file name (max 100 characters): "));
    read(0, file, 100);
    file[strlen(file) - 1] = 0;
    int f = open(file, O_RDWR), size = 0;
    if(f == -1) {
        write(1, "Error in opening file\n", strlen("Error in opening file\n"));
    }
    char c;
    while(read(f, &c, 1)) ++size;
    printf("Number of characters: %d\n", size);
    time_t t;
    srand((unsigned) time(&t));
    c = 'a' + (rand()%24);
    write(f, &c, 1);
    c = 'a' + (rand()%24); 
    if(size&1^1) write(f, &c, 1);
    close(f);
    write(1, "Success!\n", strlen("Success!\n"));
    return 0;
}