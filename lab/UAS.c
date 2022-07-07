#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct students {
    char id[20];
    char name[25];
    char time[25];
};

struct node {
    struct students student;
    struct node* left;
    struct node* right;
};

struct node* root = NULL;
int count = 0;

struct node* createNewNode(char tempID[], char tempName[], char tempTime[]) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));

    strcpy(newNode->student.id, tempID);
    strcpy(newNode->student.name, tempName);
    strcpy(newNode->student.time, tempTime);
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
    system("PAUSE");
}

struct node* insert(char tempID[], char tempName[], char tempTime[], struct node* root) {

    if (root == NULL) {
        return createNewNode(tempID, tempName, tempTime);

    }
    else if (strcmp(tempID, root->student.id) > 0) {
        root->right = insert(tempID, tempName, tempTime, root->right);

    }
    else if (strcmp(tempID, root->student.id) < 0) {
        root->left = insert(tempID, tempName, tempTime, root->left);
    }
    return root;
}

void printInOrder(struct node* root) {
    if (root != NULL) {
        printInOrder(root->left);
        count++;
        printf("| %-3d | %-20s | %-25s | %-15s |\n", count, root->student.id, root->student.name, root->student.time);
        printInOrder(root->right);
    }
}

struct node* inStudent() {
    char tempID[20], tempName[25], tempTime[25];

    printf("Insert Stundent's ID (NIM): ");
    scanf(" %[^\n]", tempID);
    getchar();
    printf("Insert Student's Name: ");
    scanf(" %[^\n]", tempName);
    getchar();

    time_t t;
    struct tm* timeinfo;
    time(&t);
    timeinfo = localtime(&t);
    sprintf(tempTime, "%02d:%02d:%02d\0", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    printf("Current Time: %s\n", tempTime);

    root = insert(tempID, tempName, tempTime, root);
    system("PAUSE");
    return root;
}

void showStudents(struct node* root) {
    printf("%s", "============================================================================\n");
    printf("| %-3s | %-20s | %-25s | %-15s |\n", "No", "ID Number", "Name", "Attendance Time");
    printf("%s", "============================================================================\n");
    if (root != NULL) {
        printInOrder(root);
    }
    else printf("| %-72s |\n", "NO ATTENDANCE INFORMATION");
    printf("%s", "============================================================================\n");
    count = 0;
    system("PAUSE");
}

int search(char key[], struct node *root){

    if(root == NULL){
        return -1;

    }else if(strcmp(key, root->student.id) == 0){
        printf("ID: %s\n", root->student.id);
        printf("Name: %s\n", root->student.name);
        printf("Attendance time: %s\n", root->student.time);
        return 1;

    }else{
        if(strcmp(key, root->student.id) > 0){
            search(key, root->right);
        }else if(strcmp(key, root->student.id) < 0){
            search(key, root->left);
        }

    }
}

void searchStudent(struct node *root){
    char checkID[25];
    int status = 0;

    system("CLS");

    if(root == NULL){
        puts("NO ATTENDANCE INFORMATION");
    }else{
        
        printf("\tSearch Student\n");
        printf("Insert Student's ID: ");
        scanf(" %[^\n]", checkID);

        system("CLS");
        status = search(checkID, root);
    }

    if(status == -1){
        puts("NO DATA OF THAT ID");
    } 
    
    system("PAUSE");
    return;
}

void main() {
    int selection;

    while (1) {
        system("CLS");
        puts("\tMAIN MENU");
        puts("1. Input Student Attendance");
        puts("2. Show Students Attendance Record");
        puts("3. Search Student's Attendance");
        puts("0. EXIT");
        printf(">> ");
        scanf("%d", &selection);
        switch (selection) {
        case 1:
            root = inStudent();
            break;
        case 2:
            showStudents(root);
            break;
        case 3:
            searchStudent(root);
            break;
        case 0:
            return;
        default:
            puts("Error Command Please Try Again!");
            system("PAUSE");
        }
    }
}
