#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

char stack[50];
int top = -1;

bool isOperand(char operand_){
    if(isalnum(operand_) != 0){
        return true;
    }else false;
}

void push(char operator_){
    top++;
    stack[top] = operator_;
}

void pop(){
    top--;
}

int main(){
    char exp[100];
    
    printf("Input Infix Expression: ");
    scanf("%s", exp);

    char *curr;
    curr = exp;
    
    while(*curr != '\0'){

        if(isOperand){
        //Checking for operand
            printf("%c", *curr);
        }else if(*curr == '('){
        //Push ( to stack
            push(*curr);
        }else if(*curr == ')'){
        //Pop stack between ( )
            while(stack[top] != '('){
                printf("%c ", stack[top]);
                pop();
            }
            pop();
        }
    }
}