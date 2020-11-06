/*
    Develop a program to create a database of students of an Institute. 
    Allow the users to search the database based on some user input, 
    such as Student's name, roll, semester, marks, etc. Use structure and union to create the database. 
    Decide yourself what are the fields you want to keep in your database.
*/

#include <stdio.h>
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

bool nSearch(db data[], int size);
bool rSearch(db data[], int size);
bool mSearch(db data[], int size);
bool dSearch(db data[], int size);

int main() {
    printf("Enter Number of students: ");
    int n; scanf("%d", &n);
    db std[n];
    for(int i=0; i<n; ++i){
        printf("DETAILS OF STUDENT #%d:\n", i+1);
        printf("Enter Full Name of the Student: ");
        scanf(" %[^\n]*c", std[i].name);
        printf("Enter Department of the Student: ");
        scanf(" %[^\n]*c", std[i].dept);
        printf("Enter Roll Number of the Student: ");
        scanf(" %d", &std[i].roll);
        printf("Enter Marks obtained by the Student: ");
        scanf(" %d", &std[i].marks);
        printf("Is the student a dayscholar or a hostel boarder? Enter 'h' for hoster boarder or 'd' for day scholar: ");
        char bs; scanf(" %c", &bs);
        strcpy(std[i].data.hName, "");
        if(bs == 'h'){
            printf("Enter Hostel Name: ");
            scanf(" %[^\n]*c", std[i].data.hName);
        }
        puts("");
    }

    puts("Do you want to search? (y/n)");
    char s; scanf(" %c", &s);
    bool search = (s == 'y' ? true : false);
    bool (*fn[4])(db stdata[], int size) = {nSearch, rSearch, mSearch, dSearch};
    while(search){
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
        if(!fn[sq-1](std, n)){
            puts("Not Found!");
        }
        puts("Do you want to search? (y/n)");
        scanf(" %c", &s);
        search = (s == 'y' ? true : false);
    }
    return 0;
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

bool nSearch(db data[], int size) {
    printf("Enter Student Name: ");
    bool found = false;
    char name[100]; scanf(" %[^\n]*c", name);
    for(int i=0; i<size; ++i){
        if(!strcmp(name, data[i].name)){
            found = true;
            displayData(data[i]);
        }
    }
    return found;
}

bool rSearch(db data[], int size) {
    bool found = false;
    printf("Enter Student Roll Number: ");
    int roll; scanf(" %d", &roll);
    for(int i=0; i<size; ++i){
        if(roll == data[i].roll){
            found = true;
            displayData(data[i]);
        }
    }
    return found;
}

bool mSearch(db data[], int size) {
    printf("Enter Marks Obtained: ");
    bool found = false;
    int marks; scanf(" %d", &marks);
    for(int i=0; i<size; ++i){
        if(marks == data[i].marks){
            found = true;
            displayData(data[i]);
        }
    }
    return found;
}

bool dSearch(db data[], int size) {
    printf("Enter Student Department: ");
    bool found = false;
    char dept[100]; scanf(" %[^\n]*c", dept);
    for(int i=0; i<size; ++i){
        if(!strcmp(dept, data[i].dept)){
            found = true;
            displayData(data[i]);
        }
    }
    return found;
}