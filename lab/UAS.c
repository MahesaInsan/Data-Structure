#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct students{
    char id[20];
    char name[25];
    char time[10];
};

struct node{
    struct students student;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

void inStudent(){
    char tempID[20], tempName[25], tempTime[10];

    printf("Insert Stundent's ID (NIM): ");
    scanf(" %[^\n]", tempID);
    printf("Insert Student's Name: ");
    scanf(" %[^\n]", tempName);
    
    time_t rawtime;
    struct tm * timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    printf("Current Time: %s", tempTime);
}

void main(){
    int selection;

    while(1){
        system("cls");
        puts("\tMAIN MENU");
        puts("1. Input Student Attendance");
        puts("2. Show Students Attendance Record");
        puts("3. Search Student's Attendance");
        puts("0. EXIT");
        printf(">> ");
        scanf("%d", &selection);
        switch(selection){
            case 1:
                inStudent();
                break;
            case 2:
                showStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 0:
                return;
        }
    }

}