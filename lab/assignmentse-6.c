#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
    char flight[5];
    char Fname[20];
    char Lname[20];
    int seatnum;
    char seatchar;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *tail = NULL;

struct node *createNewNode(char flight[], char Fname[], char Lname[], int seatnum, char seatchar){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));

    strcpy(newNode->flight, flight);
    strcpy(newNode->Fname, Fname);
    strcpy(newNode->Lname, Lname);
    newNode->seatnum = seatnum;
    newNode->seatchar = seatchar;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

void checkIn(){
    char tempflight[5], tempFname[20], tempLname[20];

    puts("\t INPUT PASSENGER DATA");
    printf("Flight Code: ");
    scanf(" %s", tempflight);
    printf("First Name: ");
    scanf(" %s", tempFname);
    printf("Last Name: ");
    scanf(" %s", tempLname);

    time_t t;
    srand((unsigned) time(&t));
    int tempseatnum = rand() % 60;
    char  tempseatchar = 'A' + (rand() % 5);

    struct node *newNode = createNewNode(tempflight, tempFname, tempLname, tempseatnum, tempseatchar);
    
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }else{
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    system("PAUSE");

}

void call(){
    FILE *fp = fopen("flightinfo.txt", "a");

    struct node *curr = head;
    char flight[5];

    printf("Input which flight you want to call: ");
    scanf(" %s", flight);

    if(head != NULL){
        while(curr->next != NULL){

            if(strcmp(curr->flight, flight) == 0){
                printf("Calling %s %s of flight %s to board the aeroplane!\n", curr->Fname, curr->Lname, curr->flight);
                fprintf(fp, "%s - %s - %s - %d%c\n", curr->flight, curr->Fname, curr->Lname, curr->seatnum, curr->seatchar);
            }

            curr = curr->next;

        }

        if(strcmp(curr->flight, flight) == 0){
            printf("Calling %s %s of flight %s to board the aeroplane!\n", curr->Fname, curr->Lname, curr->flight);
            fprintf(fp, "%s - %s - %s - %d%c\n", curr->flight, curr->Fname,  curr->Lname, curr->seatnum, curr->seatchar);
        }

    }else printf("No Data\n");

    fclose(fp);

    system("PAUSE");

}

void search(){
    struct node *curr = head;
    char Fname[20];

    printf("Input whose seat you want to find (First Name): ");
    scanf(" %s", Fname);

    if(head != NULL){
        
        if(strcmp(head->Fname, Fname) == 0){
            printf("Your seat number is: %d%c\n", head->seatnum, head->seatchar);

        }else if(strcmp(tail->Fname, Fname) == 0){
            printf("Your seat number is: %d%c\n", tail->seatnum, tail->seatchar);

        }else{
            while((curr->next != NULL) && (strcmp(curr->next->Fname, Fname) != 0)){
                curr = curr->next;
            }

            if(curr->next != NULL){
                printf("Your seat number is: %d%c\n", curr->seatnum, curr->seatchar);

            }else{
                printf("Data not found\n");
            }

        }

    }else printf("No Data\n");

    system("PAUSE");

}

void cancel(){
    /* Function Cancel kadang error */ 
    struct node *curr = head;
    struct node *del;
    char Fname[20];

    printf("Input whose flight you want to cancel (First Name): ");
    scanf(" %s", Fname);

    if(head != NULL){

        if(strcmp(head->Fname, Fname) == 0){
            if(head != tail){
                head = head->next;
                head->prev = NULL;
                free(del);
                puts("Data has been deleted !");

            }else{
                del = head;
                free(del);
                head = NULL;
                tail = NULL;    
                puts("Data has been deleted !");

            }

        }else if(strcmp(tail->Fname, Fname) == 0){
            if(head != tail){
                del = tail;
                tail = tail->prev;
                tail->next = NULL;
                free(del);
                puts("Data has been deleted !");

            }else{
                del = head;
                free(del);
                head = NULL;
                tail = NULL;
                puts("Data has been deleted !");

            }

        }else{
            
            while((curr->next != NULL) && (strcmp(curr->next->Fname, Fname) != 0)){
                curr = curr->next;
            }

            if(curr->next != NULL){
                del = curr->next;
                curr->next->next->prev = curr;
                curr->next = curr->next->next;
                free(del);
                puts("Data has been deleted !");

            }else{
                printf("Data not found\n");
            }
        }

    }else printf("No Data\n");

    system("PAUSE");

}

void report(){
    /* Count flight belum diimplementasikan */
    struct node *curr = head;
    int passenger = 1;

    while(curr->next != NULL){
        passenger += 1;
        curr = curr->next;
    }

    printf("Passenger Count is %d\n", passenger);

    system("PAUSE");

}

void leave(){
    struct node *curr = head;
    FILE *fp = fopen("flightinfo.txt", "w");

    while(head != NULL){
        curr = head;
        head = curr->next;
        free(curr);
    }

    printf("HAVE A NICE FLIGHT");

    fprintf(fp, "\0");
    fclose(fp);

}

void main(){
    int select;

    while(1){
        system("CLS");
        puts("\t MAIN MENU");
        puts("1. Passenger Check In");
        puts("2. Call Passenger to Board");
        puts("3. Find Seat Number");
        puts("4. Cancellation");
        puts("5. Report");
        puts("0. EXIT");


        printf(">> ");
        scanf("%d", &select);

        switch(select){
            case 1:
                checkIn();
                break;
            case 2:
                call();
                break;
            case 3:
                search();
                break;
            case 4:
                cancel();
                break;
            case 5:
                report();
                break;
            case 0:
                leave();
                return;
            default:
                puts("Error Input, Try Again");
                system("PAUSE");    
        }
    }

}

