#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int id = 0;

struct dam{
    char date[10];
    float height;
    float rain;
};
struct dam day[31];

int search(char key[10]){

    for(int i = 0; i < id; i++){
        if(strcmp(day[i].date, key) == 0){
            return i;
        }else continue;
    }
    return -1;

}

void inputData(){
    char select;

    system("cls");

    while(id < 31){
        printf("\tDay %d\n", id+1);
        printf("Input date(dd/mm/yy): ");
        scanf("%s", day[id].date);
        printf("Input height: ");
        scanf("%f", &day[id].height);
        printf("Input rainfall: ");
        scanf("%f", &day[id].rain);
        getchar();
        
        while(1){
            printf("Input another data?(Y/N): ");
            scanf("%c", &select);
            if(select == 'N'){
                id++;
                return;
            } else if(select == 'Y'){ 
                id++;
                break;
            } else printf("Invalid Input\n");
        }

    }
    
}

void searchData(){
    char key[10];
    int index;
    struct dam *pointer;

    while(1){
        system("cls");
        printf("Input the date that you want to search(dd/mm/yy): ");
        scanf("%s", &key);
        index = search(key);
        pointer = &day[index];

        if(index != -1){
            printf("\t%s\n", pointer->date);
            printf("Height: %.2f\n", pointer->height);
            printf("Rainfall: %.2f\n", pointer->rain);
            system("PAUSE");
            return;
        }else printf("Invalid Date, Please Try Again!\n");

    }

}

void showData(){
    system("cls");
    
    float minh = 9999999, maxh = 0, minr = 9999999, maxr = 0, totalh = 0, totalr = 0;
    struct dam *pointer;

    for(int i = 0; i < id; i++){
        pointer = &day[i];

        if(pointer->height < minh){
            minh = pointer->height;
        }

        if(pointer->height > maxh){
            maxh = pointer->height;
        }

        if(pointer->rain < minr){
            minr = pointer->rain;
        }

        if(pointer->height > maxr){
            maxr = pointer->rain;
        }

        totalh += pointer->height;
        totalr += pointer->rain;

    }

    printf("Max height of the dam is %.2f\n", maxh);
    printf("Min height of the dam is %.2f\n\n", minh);

    printf("Max of the rainfall is %.2f\n", maxr);
    printf("Min of the rainfall is %.2f\n\n", minr);

    printf("Average height of the dam is %.2f\n", totalh/id);
    printf("Average rainfall is %.2f\n", totalr/id);
    system("pause");

}

void main(){
    int selection;

    while(1){

        printf("\tMENU\n");
        printf("1. Input data\n");
        printf("2. Search data\n");
        printf("3. Show data\n");
        printf("0. EXIT\n");
        printf("Input your selection number: ");
        scanf("%d", &selection);

        switch (selection){
            case 1: 
                inputData();
                system("cls");
                break;
            case 2:
                searchData();
                system("cls");
                break;
            case 3:
                showData();
                system("cls");
                break;
            case 0:
                return;
            default:
                system("cls");
                printf("Invalid input try again!\n");
        }

    }

}