/*
    Write a program like "ls" in Unix/Linux which takes input from command line.
*/

#include <stdio.h>
#include <dirent.h>
#define  size 100

int main(int argc, char **argv) {
    DIR *dir; struct dirent *dirr;
    if(argc < 2){
        puts("Directory name not specified!");
        return 1;
    }
    dir = opendir(argv[1]);
    if(dir) {
        while(dirr = readdir(dir))  printf("%s\n", dirr->d_name);
        closedir(dir);
    }
    else puts("Error in opening path.");
    return 0;
}