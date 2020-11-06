/*
    Modify your program for Assignment 9 to store the data in a file. 
    Additionally, a user should be able to dynamically add new records in the file.

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef union boardingStatus {
    bool isHosteler;
    char hName[100];
} bstat;

typedef struct studentsDatabase {
    char name[100];
    int roll;
    int marks;
    char dept[100];
    bstat data;
} db;

bool nSearch(FILE* f, int size);
bool rSearch(FILE* f, int size);
bool mSearch(FILE* f, int size);
bool dSearch(FILE* f, int size);
void search();
void add();

int main() {
    printf("Enter Number of students: ");
    int n; scanf("%d", &n);
    db std;
    FILE *f;
    if(!(f = fopen("std.db", "wb"))) {
        puts("Error in opening file. Aborting!");
        exit(1);
    }
    for(int i=0; i<n; ++i){
        printf("DETAILS OF STUDENT #%d:\n", i+1);
        printf("Enter Full Name of the Student: ");
        scanf(" %[^\n]*c", std.name);
        printf("Enter Department of the Student: ");
        scanf(" %[^\n]*c", std.dept);
        printf("Enter Roll Number of the Student: ");
        scanf(" %d", &std.roll);
        printf("Enter Marks obtained by the Student: ");
        scanf(" %d", &std.marks);
        printf("Is the student a dayscholar or a hostel boarder? Enter 'h' for hoster boarder or 'd' for day scholar: ");
        char bs; scanf(" %c", &bs);
        strcpy(std.data.hName, "");
        if(bs == 'h'){
            printf("Enter Hostel Name: ");
            scanf(" %[^\n]*c", std.data.hName);
        }
        puts("");

        fwrite(&std, sizeof(db), 1, f); 
    }
    fclose(f);
    
    while(true){
        printf("1. Search\n2. Add Data\n3. Exit\nEnter Your choice (1-3): ");
        int q; scanf(" %d", &q);
        if(q==3) break;
        switch (q)
        {
        case 1:
            search();
            break;
        
        case 2:
            add();
            break;

        default:
            puts("Wrong Choice! Try Again!!");
            continue;
            break;
        }

    }
    return 0;
}

void search(){
    bool (*fn[4])(FILE*, int) = {nSearch, rSearch, mSearch, dSearch};
    enter: 
    puts("Choose Search Query: ");
    puts("1. Student Name");
    puts("2. Student Roll Number");
    puts("3. Student Marks");
    puts("4. Student Department");
    printf("Enter your choice (1-4): ");
    int sq; scanf(" %d", &sq);
    if(sq<1 || sq>4) {
        puts("Wrong Choice! Try Again!!");
        goto enter;
    }
    FILE *f;
    if(!(f = fopen("std.db", "rb"))) {
        puts("Error in opening file. Aborting!");
        exit(1);
    }
    fseek(f, 0L, SEEK_END);
    int size = ftell(f)/sizeof(db);
    fseek(f, 0L, SEEK_SET);
    if(!fn[sq-1](f, size)){
        puts("Not Found!");
    }
    fclose(f);
}

void add(){
    FILE *f;
    if(!(f = fopen("std.db", "ab"))) {
        puts("Error in opening file. Aborting!");
        exit(1);
    }
    puts("Enter the number of students for new data: ");
    int n; scanf(" %d", &n);
    db std;
    for(int i=0; i<n; ++i){
        printf("DETAILS OF STUDENT #%d:\n", i+1);
        printf("Enter Full Name of the Student: ");
        scanf(" %[^\n]*c", std.name);
        printf("Enter Department of the Student: ");
        scanf(" %[^\n]*c", std.dept);
        printf("Enter Roll Number of the Student: ");
        scanf(" %d", &std.roll);
        printf("Enter Marks obtained by the Student: ");
        scanf(" %d", &std.marks);
        printf("Is the student a dayscholar or a hostel boarder? Enter 'h' for hoster boarder or 'd' for day scholar: ");
        char bs; scanf(" %c", &bs);
        strcpy(std.data.hName, "");
        if(bs == 'h'){
            printf("Enter Hostel Name: ");
            scanf(" %[^\n]*c", std.data.hName);
        }
        puts("");

        fwrite(&std, sizeof(db), 1, f); 
    }
    fclose(f);
}

bool displayData(db dat){
    printf("\nName : %s\n", dat.name);
    printf("Roll Number: %d\n", dat.roll);
    printf("Department: %s\n", dat.dept);
    printf("Marks Obtained: %d\n", dat.marks);
    if(dat.data.isHosteler){
        printf("Hostel: %s\n", dat.data.hName);
    }
    else {
        puts("Day Scholar");
    }
    printf("\n");
}

bool nSearch(FILE* f, int size) {
    printf("Enter Student Name: ");
    bool found = false;
    db data;
    char name[100]; scanf(" %[^\n]*c", name);
    for(int i=0; i<size; ++i){
        fread(&data, sizeof(db), 1, f); 
        if(!strcmp(name, data.name)){
            found = true;
            displayData(data);
        }
    }
    return found;
}

bool rSearch(FILE* f, int size) {
    bool found = false;
    db data;
    printf("Enter Student Roll Number: ");
    int roll; scanf(" %d", &roll);
    for(int i=0; i<size; ++i){
        fread(&data, sizeof(db), 1, f);
        if(roll == data.roll){
            found = true;
            displayData(data);
        }
    }
    return found;
}

bool mSearch(FILE* f, int size) {
    printf("Enter Marks Obtained: ");
    bool found = false;
    db data;
    int marks; scanf(" %d", &marks);
    for(int i=0; i<size; ++i){
        fread(&data, sizeof(db), 1, f);
        if(marks == data.marks){
            found = true;
            displayData(data);
        }
    }
    return found;
}

bool dSearch(FILE* f, int size) {
    printf("Enter Student Department: ");
    bool found = false;
    db data;
    char dept[100]; scanf(" %[^\n]*c", dept);
    for(int i=0; i<size; ++i){
        fread(&data, sizeof(db), 1, f);
        if(!strcmp(dept, data.dept)){
            found = true;
            displayData(data);
        }
    }
    return found;
}