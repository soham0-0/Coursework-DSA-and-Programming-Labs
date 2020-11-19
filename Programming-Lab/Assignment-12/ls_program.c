/*
    Write a program using these functions to open and list out the content of a 
    given directory (like "ls" in Unix/Linux systems) of your system. Take directory name as user input.
*/

#include <stdio.h>
#include <dirent.h>
#define  size 100

int main() {
    char path[size]; DIR *dir; struct dirent *dirr;
    printf("Enter Path: ");
    scanf("%s", path);
    dir = opendir(path);
    if(dir) {
        while(dirr = readdir(dir))  printf("%s\n", dirr->d_name);
        closedir(dir);
    }
    else puts("Error in opening path.");
    return 0;
}