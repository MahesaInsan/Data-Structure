#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
    char data;
    struct node *next;
};

struct node *top = NULL;

struct node *createNewNode(char data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void push(){
    char data;
    printf("INPUT WORD: ");

    while(1){
        scanf("%c", &data);
        if(data != '\n'){
            struct node *newNode = createNewNode(data);
            if(top == NULL){
                top = newNode;
            }else{
                newNode->next = top;
                top = newNode;
            }
        }else break;
    }

}

void pop(){
    struct node *curr = top;
    struct node *del;

    printf("WORD REVERSED: ");

    if(top == NULL){
        puts("No Data In Stack");
        return;
    }else{
        while(curr != NULL){
            printf("%c", curr->data);
            del = curr;
            curr = curr->next;
            top = curr;
            free(del);
        }
    }
    printf("\n");

}

void main(){
    int select;

    while(1){
        printf("\tMAIN MENU\n");
        printf("1. Input Word\n");
        printf("2. Reverse Word\n");
        printf("0. EXIT\n");
        printf(">> ");
        scanf("%d", &select);
        getchar();

        switch(select){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 0:
                return;
            default:
                printf("Invalid input\n");

        }
    }

}
