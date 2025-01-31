#include <stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAX_LEN 5
typedef struct Stack{
    int top;
    int arr[MAX_LEN];
}Stack;

void intialize(Stack *st){
    st->top=-1;
}

int isEmpty(Stack *st){
    return st->top==-1;
}

int isFull(Stack *st){
     return st->top==MAX_LEN-1;
}

void push(Stack *st, int val){
    if(isFull(st)){
        printf("Can't push elements, the stack is full.\n");
        return;
    }
    st->arr[++(st->top)]=val;
}

void pop(Stack *st){
    if(isEmpty(st)){
        printf("Can't pop elements, the stack is empty.\n");
        return;
    }
    st->top--;
    printf("Successfully popped the top element.\n");
}

int peak(Stack *st){
    if(isEmpty(st)){
        printf("Can't return top element, the stack is empty.\n");
        return INT_MAX;
    }
    return st->arr[st->top];
}

int getSize(Stack *st){
    return st->top+1;
}

void display(Stack *st){
    if(isEmpty(st)){
        printf("Can't display elements, the stack is empty.\n");
        return;
    }
    printf("The elements in stack are:\n");
    for(int i=st->top; i>=0; i--){
        printf("%d ", st->arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter total number of operations:\n");
    scanf("%d", &n);
    Stack st;
    intialize(&st);
    
    while(n--){
        int choice;
        printf("Enter the choice of operation:\n1.Add element to stack.\n2.Remove element from stack.\n");
        printf("3.Display elements of stack.\n4.Get size of stack.\n5.Check stack is empty or not.\n");
        printf("6.Get the top element.\n7.Exit the program.\n");
        scanf("%d", &choice);
        switch(choice){
        case 1:
        printf("Enter the data:");
        int val;
        scanf("%d", &val);
        push(&st, val);
        break;
        case 2:pop(&st);
        break;
        case 3:display(&st);
        break;
        case 4:
        printf("The size of stack is: %d\n",getSize(&st));
        break;
        case 5:
        if(isEmpty(&st)){
            printf("Stack is empty.\n");
        }else{
            printf("Stack is not empty.\n");
        }
        break;
        case 6: 
        int topElement=peak(&st);
        if(topElement!=INT_MAX){
            printf("The top element is %d", peak(&st));
        }
        break;
        case 7: return 0;
        default:
            break;
        }
    }
    return 0;
}
