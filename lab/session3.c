#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int age;
    char name[20];
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *tail = NULL;

struct node *createNewNode(int age, char name[]){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));

    newNode->age = age;
    strcpy(newNode->name, name);
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

void inHead(){
    int age;
    char name[20];

    printf("\tINSERT HEAD\n");
    printf("Insert Age: ");
    scanf("%d", &age);
    printf("Insert Name: ");
    scanf(" %[^\n]", name);

    struct node *newNode = createNewNode(age, name);

    if(head == NULL){
        head = newNode;
        tail = newNode;
    }else{
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

}

void inTail(){
    int age;
    char name[20];

    printf("\tINSERT TAIL\n");
    printf("Insert Age: ");
    scanf("%d", &age);
    printf("Insert Name: ");
    scanf(" %[^\n]", name);

    struct node *newNode = createNewNode(age, name);
    
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }else{
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    struct node* delete = head;
    tail->next = head->next;
    head = head->next;

}

void inMid(){
    struct node *curr = head;
    int age;
    char name[20];

    printf("\tINSERT MID\n");
    printf("Insert Age: ");
    scanf("%d", &age);
    printf("Insert Name: ");
    scanf(" %[^\n]", name);

    struct node *newNode = createNewNode(age, name);
    
    if(head == NULL){
        head = newNode;
        tail = newNode;

    }else if(head->age >= age){
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        
    }else if(tail->age < age){
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    
    }else{
        while(curr->next->next != NULL && curr->next->next->age <= age){
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next->prev = newNode;
        newNode->prev = curr;
        curr->next = newNode;
    
    }

}

void view(){
    printf("\tDATA in LINK LIST: \n");

    struct node *curr = head;
    printf("NULL <==> ");
    while(curr != NULL){
        printf("[%d - %s] <==> ", curr->age, curr->name);
        curr = curr->next;
    }
    printf("NULL\n");

}

void delHead(){
    struct node *del = head;

    if(head != NULL && head != tail){
        head = head->next;
        head->prev = NULL;
        free(del);

    }else if(head != NULL && head == tail){
        free(del);
        head = NULL;
        tail = NULL;

    }else printf("No Head\n");

}

void delTail(){
    struct node *del = tail;
    
    if(head != NULL && head != tail){
        tail = tail->prev;
        tail->next = NULL;
        free(del);

    }else if(head != NULL && head == tail){
        free(del);
        head = NULL;
        tail = NULL;

    }else printf("No Head\n");

}

void delMid(){
    struct node *curr = head;
    struct node *del;
    char name[20];

    printf("Input whose data you want to delete: ");
    scanf(" %[^\n]", name);

    if(head != NULL){

        if(strcmp(head->name, name) == 0){
            if(head != tail){
                head = head->next;
                head->prev = NULL;
                free(del);

            }else{
                del = head;
                free(del);
                head = NULL;
                tail = NULL;    

            }

        }else if(strcmp(tail->name, name) == 0){
            if(head != tail){
                del = tail;
                tail = tail->prev;
                tail->next = NULL;
                free(del);

            }else{
                del = head;
                free(del);
                head = NULL;
                tail = NULL;

            }

        }else{
            
            while((curr->next != NULL) && (strcmp(curr->next->name, name) != 0)){
                curr = curr->next;
            }

            if(curr->next != NULL){
                del = curr->next;
                curr->next->next->prev = curr;
                curr->next = curr->next->next;
                free(del);

            }else{
                printf("Data not found\n");
            }
        }

    }else printf("No Head\n");

}

void leave(){
    struct node *curr = head;

    while(head != NULL){
        curr = head;
        head = curr->next;
        free(curr);
    }
    view();

}

void main(){
    int select;

    while(1){
        printf("\tMENU\n");
        printf("1. Insert Head\n");
        printf("2. Insert Tail\n");
        printf("3. Insert Mid\n");
        printf("4. View List\n");
        printf("5. Delete Head\n");
        printf("6. Delete Tail\n");
        printf("7. Delete Mid\n");
        printf("0. EXIT\n");
        
        printf(">> ");
        scanf("%d", &select);

        switch(select){
            case 1:
                inHead();
                break;
            case 2:
                inTail();
                break;
            case 3:
                inMid();
                break;
            case 4:
                view();
                break;
            case 5:
                delHead();
                break;
            case 6:
                delTail();
                break;
            case 7:
                delMid();
                break;
            case 0:
                leave();
                return;
            default:
                printf("Invalid input\n");

        }
    }   

}