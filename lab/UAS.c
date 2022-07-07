#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct students{
    char id[20];
    char name[25];
    char time[15];
};

struct node{
    struct students student;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;
int count = 0;

struct node *createNewNode(char tempID[], char tempName[], char tempTime[]){
	struct node *newNode =(struct node *)malloc (sizeof(struct node));

	strcpy(newNode->student.id, tempID);
    strcpy(newNode->student.name, tempName);
    strcpy(newNode->student.time, tempTime);
	newNode->left=NULL;
	newNode->right=NULL;
	
	return newNode;
}

struct node *insert (char tempID[], char tempName[], char tempTime[], struct node *root){

	if(root == NULL){
		return createNewNode(tempID, tempName, tempTime);

	}else if (strcpy(tempID, root->student.id) > 0){
		root->right =insert(tempID, tempName, tempTime, root->right);

	}else if (strcpy(tempID, root->student.id) < 0){
		root->left=insert(tempID, tempName, tempTime, root->left);

	}
	return root;
}

void printInOrder(struct node *root){
    if (root != NULL){
		printInOrder(root->left);
        count++;
		printf("| %-3d | %-20s | %-25s | %-15s |\n", count, root->student.id, root->student.name, root->student.time);
		printInOrder(root->right);
	}
}

struct node *inStudent(){
    char tempID[20], tempName[25], tempTime[15];

    printf("Insert Stundent's ID (NIM): ");
    scanf(" %[^\n]", tempID);
    printf("Insert Student's Name: ");
    scanf(" %[^\n]", tempName);
    
    time_t t;
    time(&t);
    strcpy(tempTime, ctime(&t));
    printf("Current Time: %s", tempTime);

    root = insert(tempID, tempName, tempTime, root);
    system("PAUSE");
    return root;
}

void showStudents(struct node *root){
    printf("%s", "============================================================================\n");
    printf("| %-3s | %-20s | %-25s | %-15s |\n", "No", "ID Number", "Name", "Attendance Time");
    printf("%s", "============================================================================\n");
    if(root != NULL){
        printInOrder(root);
    }else printf("| %-72s |\n", "NO ATTENDANCE INFORMATION");
    printf("%s", "============================================================================\n");
    count = 0;
    system("PAUSE");
}

void main(){
    int selection;

    while(1){
        system("CLS");
        puts("\tMAIN MENU");
        puts("1. Input Student Attendance");
        puts("2. Show Students Attendance Record");
        puts("3. Search Student's Attendance");
        puts("0. EXIT");
        printf(">> ");
        scanf("%d", &selection);
        switch(selection){
            case 1:
                root = inStudent();
                break;
            case 2:
                showStudents(root);
                break;
            case 3:
/*                 searchStudent(); */
                break;
            case 0:
                return;
        }
    }

}
