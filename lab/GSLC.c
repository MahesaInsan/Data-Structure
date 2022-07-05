#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

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

int precedence(char operator_){
    if(operator_ == '*' || operator_ == '/'){
        return 2;
    }else if(operator_ == '+' || operator_ == '-'){
        return 1;
    }else return 0;

}

int main(){
    char exp[100] = {'\0'};
    
    printf("Input Infix Expression: ");
    scanf("%s", exp);
    printf("%s\n", exp);

    char rev_exp[100] = {'\0'};
    int i = strlen(exp)-1;
    int j = 0;

    while(exp[i] != '\0'){
        if(exp[i] == '('){
            rev_exp[j] = ')';

        }else if(exp[i] == ')'){
            rev_exp[j] = '(';

        }else rev_exp[j] = exp[i];
        i--;
        j++;
    }

    printf("%s\n", rev_exp);

    char *curr;
    curr = rev_exp;

    char postfix_exp[100] = {'\0'};
    int k = -1;

    while(*curr != '\0'){

        if(isOperand(*curr) == true){
            push(*curr);
            k++;

        }else{
            pop(*curr);

        }

        curr++;
    }

    while(top != -1){
        k++;
        postfix_exp[k] = stack[top];
        pop();
    }

    printf("%s\n", postfix_exp);

    char prefix_exp[100] = {'\0'};
    i = strlen(postfix_exp)-1;
    j = 0;

    while(postfix_exp[i] != '\0'){
        prefix_exp[j] = postfix_exp[i];
        i--;
        j++;
    }

    printf("%s\n", prefix_exp);

}