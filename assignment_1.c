/* 
Infix to Postfix

Use a stack to hold operators.
Output operands immediately.
Pop operators from the stack according to precedence. 
*/


/* 
Note: I did refer to the following site which has a code
for  infix to postfix notation conversion which I used to
understand and write the code: https://www.programming9.com/programs/c-programs/230-c-program-to-convert-infix-to-postfix-expression-using-stack 
*/
#include<stdio.h>
#include<ctype.h>

char stack[50]; // defining stack
int top = -1; // stack is empty

// define push and pop operations
void push(char a)
{
    stack[++top] = a;
}

char pop() {
    if (top == -1)
        return -1; // if empty return -1 to signify that
    else
        return stack[top--]; // returns topmost value then removes it
}

// function to decide which operation are pushed first, second, etc
int priority(char a)
{
    if (a == '(')
        return 0;
    if (a == '+' || a == '-')
        return 1;
    if (a == '*' || a == '/')
        return 2;
    return 0;
}

int main() {
    char op[50]; // operation
    char *p, a; 
    printf("Enter your operation, ensure that there are no spaces in between the operands, parentheses and operators: ");
    scanf("%49s", op);
    printf("\n");
    p = op;

    while(*p != '\0') // repeat until op finishes
    {
        if (isalnum(*p)) // checks if input is alphanumeric
            printf("%c ", *p);
        else if(*p == '(')
            push(*p);
        else if(*p == ')'){
            // tries to find the corresponding open bracket
            while (top != -1 && (a = pop()) != '(') 
                printf("%c ", a);
            if (top != -1)
                pop();

        }
        else
        {
            while (top != -1 && priority(stack[top]) >= priority(*p))
            {
                printf("%c ", pop());
            }
            push(*p);
        }
    p++;
    }
    // pops remaining operators
    while(top != -1) 
    {
        printf("%c ",pop());
    }
    printf("\n");
    return 0;
}


